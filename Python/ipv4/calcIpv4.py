import re


class CalcIpv4:
    """Calculates Ivp4 networks.
    
    Uses:\n
        1) network = CalcIPv4(ip='192.168.0.128', prefix=10)\n
        2) network = CalcIPv4(ip='192.168.0.128', mask='255.255.255.0')
    """
    
    def __init__(self, ip, mask = None, prefix = None):
        
        if not mask and not prefix:
            raise ValueError("Must specify either the network prefix or mask.")
        elif mask and prefix:
            raise ValueError("Must specify either the network prefix or mask. Not both.")
        
        self.ip = ip
        self.mask = mask
        self.prefix = prefix
        self._set_broadcast()
        self._set_network()
        
    @property
    def ip(self):
        return self._ip
    
    @property
    def mask(self):
        return self._mask
    
    @property
    def prefix(self):
        return self._prefix
    
    @property
    def network(self):
        return self._network
    
    @property
    def broadcast(self):
        return self._broadcast
    
    @property
    def num_ips(self):
        return self._get_num_ips(self)
    
    @property
    def num_hosts(self):
        return self._get_num_ips(self) - 2
    
    @ip.setter
    def ip(self, ip):
        if not self._validate_ip(ip):
            raise ValueError("Invalid IP address.")
        self._ip = ip
        self._binary_ip = self._tobinary(ip)
        
    @mask.setter
    def mask(self, mask):
        if not mask:
            return
        elif not self._validate_ip(mask):
            raise ValueError("Invalid mask.")
        self._mask = mask
        self._binary_mask = self._tobinary(mask)
        if not hasattr(self, 'prefix'):
            self.prefix = self._binary_mask.count('1')
    
    @prefix.setter
    def prefix(self, prefix):
        if not prefix:
            return
        try:
            numeric = int(prefix)
        except:
            raise TypeError("Invalid prefix. Must a valid int value for the number of bits of a prefix.")
        if prefix > 32:
            raise ValueError("Invalid prefix. Must be less than or equal to 32 bits.")
        self._prefix = prefix
        self._binary_mask = (prefix * '1').ljust(32, '0')
        if not hasattr(self, 'mask'):
            print(self._binary_mask)    
            self.mask = self._toip(self._binary_mask)
            
    def details(self):
        print(
            f'IP: {self.ip}',
            f'Mask: {self.mask}',
            f'Network: {self.network}',
            f'Broadcast: {self.broadcast}',
            f'Prefix: {self.prefix}',
            f'Number of IPs: {self.num_ips}',
            f'Number of Hosts: {self.num_hosts}',
            sep='\n'
        )
    
    @staticmethod  
    def _validate_ip(ip):
        regexp = re.compile(
            r'^([0-9]{1,3}).([0-9]{1,3}).([0-9]{1,3}).([0-9]{1,3})$'
        )
        if regexp.search(ip):
            return True
        
    @staticmethod   
    def _tobinary(ip):
        blocks = ip.split('.')
        binary_blocks = [bin(int(block))[2:].zfill(8) for block in blocks]
        return ''.join(binary_blocks)
    
    @staticmethod
    def _toip(binary):
        num_blocks = 8
        blocks = [str(int(binary[i:num_blocks+i], 2)) for i in range(0, 32, num_blocks)]
        return '.'.join(blocks)
    
    def _set_broadcast(self):
        host_bits = 32 - self.prefix
        self._binary_broadcast = self._binary_ip[:self.prefix] + (host_bits * '1')
        self._broadcast = self._toip(self._binary_broadcast)
        return self._broadcast
    
    def _set_network(self):
        host_bits = 32 - self.prefix
        self._binary_network =  self._binary_ip[:self.prefix] + (host_bits * '0')
        self._network = self._toip(self._binary_network)
        return self._network
    
    def _get_num_ips(self):
        return 2 ** (32 - self.prefix)
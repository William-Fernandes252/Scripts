class Flight():
    def __init__(self, capacity):
        self.capacity = capacity
        self.passangers = []
        
    def addPassenger(self, name):
        if  not self.openSeats():
            return False    
        self.passangers.append(name)
        return True
        
    def openSeats(self):
        return self.capacity - len(self.passangers)
    
flight = Flight(3)

people = ["Harry", "Ron", "Hermione", "Ginny"]
for person in people:
    if flight.addPassenger(person):
        print(f"Added {person} to flight successfully.")
    else:
        print(f"No more seats available for {person}.")
        
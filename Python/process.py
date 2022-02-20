import subprocess

sub = subprocess.run(
    ['ping', '127.0.0.1'],
    capture_output = True,
    text = True
)

# print(sub.stderr)
# print(sub.stdout)
# print(sub.returncode)
# print(sub.args)

print(sub.stdout)
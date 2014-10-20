import sys

print 1
sys.stdout.write('a')
for i in range(0,100000):
	sys.stdout.write('b')

bars = int(input())
times = input().split()

for i in range(len(times)):
    times[i] = int(times[i])

a_comecou = False
b_comecou = False

a = 0
b = 0

atu_alice = 0
atu_bob = -1

tempo = 0

while atu_alice != len(times)+atu_bob:
    
    tempo = tempo + 1
    
    if tempo == times[atu_alice]:
        atu_alice = atu_alice + 1
        times[atu_bob] = times[atu_bob] - tempo
        tempo = 0
        a = a + 1
        a_comecou = True
        b_comecou = False
        
    if tempo == times[atu_bob]:
        atu_bob = atu_bob - 1
        times[atu_alice] = times[atu_alice] - tempo
        tempo = 0
        b = b + 1
        a_comecou = False
        b_comecou = True

if tempo == 0:
    a = a + 1
else:
    b = b + 1
    
print(b, a)

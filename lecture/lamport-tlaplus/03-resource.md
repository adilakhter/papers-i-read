# 3 Resources

- https://lamport.azurewebsites.net/tla/tla.html
- download https://github.com/tlaplus/tlaplus/releases/tag/v1.5.6
  - https://github.com/tlaplus/tlaplus/releases/download/v1.5.6/TLAToolbox-1.5.6-linux.gtk.x86_64.zip
- unzip, run the binary `toolbox` to start it
- open an empty file end with `.tla` (it seems the toolbox can't create new file)

````text
------- MODULE simple ------
EXTENDS Integers
VARIABLES i, pc   

Init == (pc = "start") /\ (i = 0)

Pick == /\ pc = "start"  
       /\ i' \in 0..1000
       /\ pc' = "middle"

Add1 == /\ pc = "middle"
       /\ i' = i + 1
       /\ pc' = "done"  

Next == Pick \/ Add1
============================
````

- run it, it will have deadlock (because it terminates?), uncheck the checkbox for deadlock to solve it ...

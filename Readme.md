# Solution
Intersection here would occur if s2>s1 and e2>e1
The following problem is what one calls a sweep line algorithm. 
From wikipedia "sweep algorithm is an algorithmic paradigm that uses a conceptual sweep line or sweep surface to solve various problems in Euclidean space." The runtime for the solution is O(nlogn). 
##How the algorithm was used here
### Step1.
Events were created based on the points angular position on the circle
### Step2
Sorting Events:The events are sorted based on the value of their position on the circle. 
### Step3
 Sweeping: As we sweep  we encounter events in a specific order. As we find starting points our event starts and as we find ending points the event ends


### Step4
 Handling Active Chords: The std::set is used to keep track of the indices of the currently active chords. When a start event is encountered, we increment the intersection count by the number of active chords because the new chord will intersect with each of them. When an end event is encountered, we remove the chord from the set of active chords, as it no longer can intersect with future chords.


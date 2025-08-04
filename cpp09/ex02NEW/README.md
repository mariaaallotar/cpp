# Ford-Johnson algorithm explained
Let us sort `8 11 13 15 9 2 1 4 5 3 12 6 10 14 7` using merge insertion as defined by Ford and Johnson
in [this paper](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf).

Let's start by following the steps found in the original paper:   
<img width="855" height="289" alt="Screenshot 2025-08-04 at 20 13 05" src="https://github.com/user-attachments/assets/f6a78d52-552f-4b62-8a7a-565f1ba30860" />

## Step 1:   
Sort the numbers into `bigger` and `smaller` by doing pairwise comparisons   
<img width="1730" height="912" alt="image" src="https://github.com/user-attachments/assets/248d5127-e14c-4a9a-b763-d7c7910759b4" />


## Step 2:   
Sort the bigger numbers found in the first step using merge insertion (this is a recursive algorithm).   
For now we will skip ***how*** the bigger numbers get sorted and procede like we would get them back sorted.   
<img width="1222" height="514" alt="image" src="https://github.com/user-attachments/assets/d149463d-ca49-4ea1-bee2-af817159c95e" />


## Step 3:
This is the important part. The algorithm relies on the following relationship between the numbers: the bigger ones are in order and the smaller number of the pair follows the bigger number.   
This can be visualized through this diagram:   
<img width="1132" height="220" alt="image" src="https://github.com/user-attachments/assets/125af169-5fbb-4308-b1e1-fb1f375ddeee" />   
The arrows respresent the relationship between the numbers, the arrow always points to the bigger of the two numbers.   

<img width="1208" height="576" alt="image" src="https://github.com/user-attachments/assets/a3907de3-9990-4b54-91d7-8df5fed0020c" />
You might notice that our numbers do not follow the important relationship that is needed for the algorithm to work optimally.   
The a:s are correct: `a1 <= a2 <= .... <= a7`. But the b:s do not follow the a:s: `b1 !< a1`. This is because whenever we move the bigger number in the pair, the smaller one ***must*** follow.   

<img width="1814" height="1358" alt="image" src="https://github.com/user-attachments/assets/2e042a13-44ca-4f5b-9796-94f028eca408" />
Now the relationships of the named numbers are correct, we can proceed.   
We can now create the `main` and the `pend`.   

# Ford-Johnson algorithm explained
Let us sort `8 11 13 15 9 2 1 4 5 3 12 6 10 14 7` using merge insertion as defined by Ford and Johnson
in [this paper](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf). The algorithm makes the least amount of comparisons possible.   

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

### 3.1 Naming the numbers
<img width="1208" height="576" alt="image" src="https://github.com/user-attachments/assets/a3907de3-9990-4b54-91d7-8df5fed0020c" />   

    
You might notice that our numbers do not follow the important relationship that is needed for the algorithm to work optimally.   
The a:s are correct: `a1 <= a2 <= .... <= a7`. But the b:s do not follow the a:s: `b1 !< a1`. This is because whenever we move the bigger number in the pair, the smaller one ***must*** follow.   

<img width="1814" height="1358" alt="image" src="https://github.com/user-attachments/assets/2e042a13-44ca-4f5b-9796-94f028eca408" />
Now the relationships of the named numbers are correct, we can proceed.   
   
### 3.2 Creating the main and the pend
<img width="1714" height="664" alt="image" src="https://github.com/user-attachments/assets/bac03484-c9e9-45a3-8207-0a914255d301" />   
The main will always be sorted. The outsider will still stay as such, because we do not now anything about it's relationship to any other number.

### 3.3 Inserting from pend to main
Inserting numbers from pend to main is done with binary insertion, this is optimal because we know that main is sorted. Because we know that `bx` is always smaller than `ax`, we only need to look for the correct spot for `bx` in main from the beginning of main until `ax`.    
   
We will be inserting the numbers in a specific order that further minimizes the comparisons made. The order is based on the Jacobsthal sequence: `0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, ...`.    
   
We will insert the numbers from pend into main starting from `b3` (3 is the first Jacobsthal number we use), then in decending order. 

<img width="1806" height="706" alt="image" src="https://github.com/user-attachments/assets/31358110-da5b-43be-842c-e1ed2aa6545c" />   
<img width="2046" height="666" alt="image" src="https://github.com/user-attachments/assets/8fdd33fa-6f2a-4208-b196-b07befe7b43c" />    


When we hit the beginning of pend we will jump to the next Jacobsthal number: 5. And start inserting starting from `b5` in decending order. 

<img width="2216" height="662" alt="image" src="https://github.com/user-attachments/assets/1d4bf898-9c7a-43e8-8047-84f4d6f1d88c" />
<img width="2262" height="644" alt="image" src="https://github.com/user-attachments/assets/0b260314-a4c4-4093-b41e-7a03d2549b67" />

You might notice that the area of search for the correct insertion position stays constant for each Jacobsthal number though we add more values into main, this is the optimization of this algorithm. 

We will increment the Jacobsthal number and insert in decending order from that so long that there is no more `bx` (x is the next Jacobsthal), at this point just insert all elements from the end of pend in decending order.   







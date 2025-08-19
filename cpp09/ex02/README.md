# Ford-Johnson algorithm explained
Let us sort `8 11 13 15 9 2 1 4 5 3 12 6 10 14 7` using merge insertion as defined by Ford and Johnson
in [this paper](https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf). The algorithm is developed to makes the least amount of comparisons possible, which makes sense when it is more time-consuming to compare values (e.g. big strings or objects) than other computations, data movement and memory accessing.   

I assume you have already read the pages 184 and 185 in the original paper and that you found it difficult to understand. If you have not, please read them before continuing with this explanation.   

Let's start by following the steps found in the original paper:   

<img width="855" height="289" alt="Screenshot 2025-08-04 at 20 13 05" src="https://github.com/user-attachments/assets/f6a78d52-552f-4b62-8a7a-565f1ba30860" />

## Index   
* [Step 1: pairwise comparisons](#step-1-pairwise-comparisons)
* [Step 2: sorting the bigger numbers](#step-2-sorting-the-bigger-numbers)
* [Step 3: relationships between the numbers](#step-3-relationships-between-the-numbers)
    * [Naming the numbers](#31-naming-the-numbers)
    * [Creating the main and the pend](32-creating-the-main-and-the-pend)
    * [Inserting from pend to main](33-inserting-from-pend-to-main)

## Step 1: pairwise comparisons

<blockquote>
"Make pairwise comparisons of [n / 2] disjoint pairs of elements. (If n is odd, leave one element out.)"
</blockquote>   

This just means: Sort the numbers into `bigger` and `smaller` by doing pairwise comparisons   

<img width="1730" height="912" alt="image" src="https://github.com/user-attachments/assets/248d5127-e14c-4a9a-b763-d7c7910759b4" />


## Step 2: sorting the bigger numbers

<blockquote>
"Sort the [n/2] larger numbers, found in step (i), by merge insertion."
</blockquote> 

This means: Sort the bigger numbers found in the first step using merge insertion (this is a recursive algorithm).   
For now we will skip ***how*** the bigger numbers get sorted and proceed like they would be returned sorted from the recursion.   

<img width="1222" height="514" alt="image" src="https://github.com/user-attachments/assets/d149463d-ca49-4ea1-bee2-af817159c95e" />


## Step 3: relationships between the numbers

This is the important part! The algorithm relies on the following relationship between the numbers: the bigger ones are in order and the smaller number of the pair follows the bigger number.   

This can be visualized through this diagram:   
<img width="1132" height="220" alt="image" src="https://github.com/user-attachments/assets/125af169-5fbb-4308-b1e1-fb1f375ddeee" />   
The arrows respresent the relationship between the numbers, the arrow always points to the bigger of the two numbers.   

### 3.1 Naming the numbers
<blockquote>
"Name the elements a1, a2, ... , a[n/2], b1, b2, ... , b[n/2] as in (7), where a1 ≤ a2 ≤ · · · ≤ a[n/2] and bi ≤ ai for 1 ≤ i ≤ [n/2]"
</blockquote>  

"as in (7)" refers to the graph in the picture above.   

<img width="2122" height="918" alt="image" src="https://github.com/user-attachments/assets/6154440d-d6e7-4522-891a-909270cd23cc" />   


You might notice that our numbers do not follow the important relationship that is needed for the algorithm to work optimally.   
The a:s are correct: `a1 <= a2 <= .... <= a7`. But the b:s do not follow the a:s: `b1 !< a1`. This is because whenever we move the bigger number in the pair, the smaller one ***must*** follow.   

Let's fix it:   
<img width="1806" height="1168" alt="image" src="https://github.com/user-attachments/assets/d5b22ca3-ef88-464a-9560-ada5211ff3ba" />   

Now the relationships of the named numbers are correct, we can proceed.   
   
### 3.2 Creating the main and the pend
<blockquote>
"call b1 and the a's the "main chain"."
</blockquote>

The rest of the b:s we will call the "pend".   

<img width="1956" height="610" alt="image" src="https://github.com/user-attachments/assets/cf1c298e-6260-4ed5-b736-ee5a6d30eddc" />   
The main will always be sorted. The outsider will still stay as such, because we do not now anything about it's relationship to any other number.

### 3.3 Inserting from pend to main
<blockquote>
"Insert the remaining b's into the main chain, using binary insertion, in the following order, leaving out all bj for j > [n/2]:
   b3,b2; b5,b4; b11,b10, ... ,b5; ... ; btk,btk-1, ... ,btk-1+1; ....
</blockquote>
We will insert numbers from pend to main with binary insertion, this is optimal because we know that main is sorted. Because we know that `bx` is always smaller than `ax`, we only need to look for the correct spot for `bx` in main from the beginning of main until `ax`.    
   
We will be inserting the numbers in a specific order that further minimizes the comparisons made. The order is based on the Jacobsthal sequence: `0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, ...`.    
   
We will insert the numbers from pend into main starting from `b3` (3 is the first Jacobsthal number we use), then in decending order. 

Note: I will not go into how binary insertion works in this explanation sinse there are many good resources on that already.   

<img width="1982" height="688" alt="image" src="https://github.com/user-attachments/assets/311456d9-ec02-415e-853f-9e774f62e9f8" />   

The red number is the number to be inserted into the main chain and the black box shows the search area for the insertion.   

<img width="2054" height="700" alt="image" src="https://github.com/user-attachments/assets/1901dc56-65de-4aaa-a426-91adce28e83f" />

---   

When we hit the beginning of pend we will jump to the next Jacobsthal number: 5. And start inserting starting from `b5` in decending order. 

<img width="2112" height="628" alt="image" src="https://github.com/user-attachments/assets/914508df-57e5-4199-b7b2-1c06aacb5d18" />
<img width="2304" height="648" alt="image" src="https://github.com/user-attachments/assets/24e0d305-5c0f-460a-870c-92bcbc633299" />

You might notice that the area of search for the correct insertion position (the black box) stays constant for each Jacobsthal number although we add more values into main, this is the optimization of this algorithm. 

We will increment the Jacobsthal number and insert in decending order from that so long that there is no more `bx` (x is the next Jacobsthal), at this point just insert all elements from the end of pend in decending order.   

<img width="1220" height="316" alt="image" src="https://github.com/user-attachments/assets/2fe749dc-b55a-49d1-9219-b19e842f1cbc" />   
   

Because ´b8´ is the ´outsider number´ (it did not have a pair in the beginning which means that we do not know it's realtion to any other number) its search area will be the whole main.    


<img width="2126" height="504" alt="image" src="https://github.com/user-attachments/assets/428e3a49-38f2-4993-a652-68ddf13a8773" />   

When the ´pend´ is empty, the ´main´ will contain all the numbers sorted. 

# Implementation

When you feel like you have a basic understanding of the algorithm try to make an implementation, either in actual code or pseudocode. Think of what containers you will use, how will you keep track of the pairs, how will you know the 'name' (a1, b1, etc.) of the number, when does the recursion end, etc.  

Do ***not*** continue this guide before you have gotten stuck in some part of the implementation.  


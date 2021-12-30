A Binary Heap is a Binary Tree with following properties.
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

## Represention
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.
Let the array be **harr[]**.

The root element will be at **harr[0]**.

Below are the indexes of other nodes for the ith node, i.e., **harr[i]** :

**harr[(i-1)/2]**	returns the parent node

**harr[(2*i)+1]** returns the left child node

**harr[(2*i)+2]** 	returns the right child node


## Heapify:
The process of reshaping a binary tree into a Heap data structure is known as 'heapify'.
Heapify method rearranges the elements of an array where the left and right sub-tree of ith element obeys the heap property.
It basically picks an index and convert that node and all the nodes below it to heap.

**NOTE:** We can call Heapify fn on a node only if all the nodes below it follow heap property.

**Algorithm for 'heapify':**

heapify(harr)
   Root = harr[0]
   Largest = largest( harr[0] , harr [2 * 0 + 1]. harr[2 * 0 + 2])
   if(Root != Largest)
       swap(Root, Largest)
       
(Largest will be replaced with smallest in case of min-heaps)

- For insertion,we start heapify from bottom-most node, i.e., follow bottom-up approach.
- For deletion, we start hepify from the node where we have placed the last node, in standard case, it is placed at the position of root. So, we follow top-down aproach.

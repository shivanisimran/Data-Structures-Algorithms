A Binary Heap is a Binary Tree with following properties.
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

# Represention
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.
Let the array be harr[].

The root element will be at harr[0].

Below are the indexes of other nodes for the ith node, i.e., harr[i]:
**Arr[(i-1)/2]**	Returns the parent node
**Arr[(2*i)+1]** Returns the left child node
**Arr[(2*i)+2]** 	Returns the right child node

### Recursion在tree题目的基本应用大致分为3类用法

- 把value从上往下传递（then 从上往下）的题目
    1.1 BST 判定方法
- 只把value从下往上传递 （更为常见，必须熟练掌握）
    - getHeight(Node* root)是经典的把 integer value (从下往上传递的题目)
    - isBalanced(Node* root)是把 boolean value (从下往上传递的题目)
    - isSymmetric(Node* node1, Node* node2) 是把 boolean value (从下往上传递的题目)
    - Assign the value of each node to be the total number of nodes that belong to its left substree. (是把integer value从下往上传递的题目)
- 只把value从下往上传递，并且用返回的值更新ans，而ans并不是返回值。

- 思路：
    - 确定选择哪种遍历方式，**前序，中序，后序**。
        - 一般如果是BST，跟顺序有关的话，采用中序 + prev 指针
        - 一般如果跟左右节点返回值有关，用后序
    - 确定当前节点需要做的操作。
        - 返回什么值
        - 需不需要update ans
        - 节点关系是什么


| ID |Question | Type |
| ----------- | ----------- | ----------- |
|94|    Binary Tree Inorder Traversal| XXX|
|95|    Unique Binary Search Trees II|XXX|	
|96|    Unique Binary Search Trees|XXX|	
|98|    Validate Binary Search Tree|XXX|
|99|    Recover Binary Search Tree|XXX|	
|100|   Same Tree|XXX|	
|101|   Symmetric Tree|XXX|	
|102|   Binary Tree Level Order Traversal|XXX|	
|103|   Binary Tree Zigzag Level Order Traversal|XXX|	
|104|	Maximum Depth of Binary Tree|XXX|	
|105|	Construct Binary Tree from Preorder and Inorder Traversal|XXX|	
|106|	Construct Binary Tree from Inorder and Postorder Traversal|XXX|
|107|	Binary Tree Level Order Traversal II|XXX|	
|108|	Convert Sorted Array to Binary Search Tree|XXX|	
|110|	Balanced Binary Tree|XXX|
|111|	Minimum Depth of Binary Tree|XXX|
|112|	Path Sum|XXX|	
|113|	Path Sum II|XXX|
|114|	Flatten Binary Tree to Linked List|XXX|
|116|	Populating Next Right Pointers in Each Node|XXX|
|117|	Populating Next Right Pointers in Each Node|XXX|
|124|	Binary Tree Maximum Path Sum|XXX|	
|129|	Sum Root to Leaf Numbers|XXX|
|144|	Binary Tree Preorder Traversal|XXX|
|145|	Binary Tree Postorder Traversal|XXX|
|156|	Binary Tree Upside Down|XXX|
|173|	Binary Search Tree Iterator|XXX|
|199|	Binary Tree Right Side View|XXX|
|222|	Count Complete Tree Nodes|XXX|	
|226|	Invert Binary Tree|XXX|
|230|	Kth Smallest Element in a BST|XXX|	
|235|	Lowest Common Ancestor of a Binary Search Tree|XXX|	
|236|	Lowest Common Ancestor of a Binary Tree|XXX|
|250|	Count Univalue Subtrees|XXX|	
|255|	Verify Preorder Sequence in Binary Search Tree|XXX|	
|257|	Binary Tree Paths|XXX|	
|270|	Closest Binary Search Tree Value|XXX|	
|272|	Closest Binary Search Tree Value II|XXX|	
|285|	Inorder Successor in BST|XXX|
|297|	Serialize and Deserialize Binary Tree|XXX|	
|298|	Binary Tree Longest Consecutive Sequence|XXX|	
|333|	Largest BST Subtree|XXX|
|337|	House Robber III|XXX|	
|366|	Find Leaves of Binary Tree|XXX|
|404|	Sum of Left Leaves|XXX|	
|426|	Convert Binary Search Tree to Sorted Doubly Linked List|XXX|
|428|	Serialize and Deserialize N-ary Tree|XXX|	
|429|	N-ary Tree Level Order Traversal|XXX|	
|431|	Encode N-ary Tree to Binary Tree|XXX|	
|437|	Path Sum III|XXX|	
|449|	Serialize and Deserialize BST|XXX|
|450|	Delete Node in a BST|XXX|
|501|	Find Mode in Binary Search Tree|XXX|
|508|	Most Frequent Subtree Sum|XXX|
|510|	Inorder Successor in BST II|XXX|
|513|	Find Bottom Left Tree Value	|XXX|
|515|	Find Largest Value in Each Tree Row|XXX|
|536|	Construct Binary Tree from String|XXX|
|538|	Convert BST to Greater Tree|XXX|
|543|	Diameter of Binary Tree|XXX|	
|545|	Boundary of Binary Tree|XXX|
|549|	Binary Tree Longest Consecutive Sequence II|XXX|
|559|	Maximum Depth of N-ary Tree|XXX|	
|563|	Binary Tree Tilt|XXX|
|572|	Subtree of Another Tree|XXX|	
|582|	Kill Process|XXX|
|589|	N-ary Tree Preorder Traversal|XXX|	
|590|	N-ary Tree Postorder Traversal|XXX|
|606|	Construct String from Binary Tree|XXX|	
|617|	Merge Two Binary Trees|XXX|
|623|	Add One Row to Tree|XXX|
|637|	Average of Levels in Binary Tree|XXX|	
|652|	Find Duplicate Subtrees|XXX|	
|653|    Two Sum IV - Input is a BST|XXX|
|654|	Maximum Binary Tree|XXX|
|655|	Print Binary Tree|XXX|
|662|	Maximum Width of Binary Tree|XXX|	
|663|	Equal Tree Partition|XXX|
|666|	Path Sum IV|XXX|
|669|	Trim a Binary Search Tree|XXX|	
|671|	Second Minimum Node In a Binary Tree|XXX|	
|684|	Redundant Connection|XXX|
|685|	Redundant Connection II|XXX|	
|687|	Longest Univalue Path|XXX|	
|700|	Search in a Binary Search Tree|XXX|	
|701|	Insert into a Binary Search Tree|XXX|	
|742|	Closest Leaf in a Binary Tree|XXX|
|814|	Binary Tree Pruning|XXX|
|834|	Sum of Distances in Tree|XXX|	
|863|	All Nodes Distance K in Binary Tree|XXX|
|865|	Smallest Subtree with all the Deepest Nodes|XXX|
|872|	Leaf-Similar Trees|XXX|
|889|	Construct Binary Tree from Preorder and Postorder Traversal|XXX|
|894|	All Possible Full Binary Trees|XXX|
|897|	Increasing Order Search Tree|XXX|	
|919|	Complete Binary Tree Inserter|XXX|
|951|	Flip Equivalent Binary Trees|XXX|
|958|	Check Completeness of a Binary Tree|XXX|
|965|	Univalued Binary Tree|XXX|	
|968|	Binary Tree Cameras|XXX|	
|971|	Flip Binary Tree To Match Preorder Traversal|XXX|
|979|	Distribute Coins in Binary Tree|XXX|
|987|	Vertical Order Traversal of a Binary Tree|XXX|
|988|	Smallest String Starting From Leaf|XXX|
|993|	Cousins in Binary Tree|XXX|	
|998|	Maximum Binary Tree II|XXX|
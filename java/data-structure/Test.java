import java.lang.reflect.Array;
import java.util.*;

public class Test {
    public static void main(String[] args) {
        /*jdk*/
        //栈
        /*java.util.Stack<Integer> stack=new java.util.Stack<Integer>();
        stack.push(3);
        stack.push(2);
        stack.push(5);
        stack.push(13);
        stack.push(7);
        stack.push(9);
        stack.push(17);
        stack.push(12);
        int top=stack.pop();*/

        /*栈*/
        /*Stack stack=new Stack(20);
        stack.push(3);
        stack.push(2);
        stack.push(5);
        stack.push(13);
        stack.push(7);
        stack.push(9);
        stack.push(17);
        stack.push(12);
        int top=stack.pop();*/

        /*循环队列*/
        /*RoundQueue queue=new RoundQueue(10);
        queue.push(3);
        queue.push(2);
        queue.push(5);
        queue.push(13);
        queue.push(7);
        queue.push(9);
        queue.push(17);
        queue.push(12);
        long top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        top=queue.pop();
        queue.push(3);
        queue.push(2);
        queue.push(5);
        queue.push(13);
        queue.push(7);
        queue.push(9);
        queue.push(17);
        queue.push(12);
        queue.push(8);//队满时元素个数为maxSize-1
        queue.push(19);
        queue.push(11);*/

        /*优先队列（数组实现）*/
        /*MaxPriorityQueue queue=new MaxPriorityQueue(20);
        queue.push(3);
        queue.push(2);
        queue.push(5);
        queue.push(13);
        queue.push(7);
        queue.push(9);
        queue.push(17);
        queue.push(12);*/

        /*堆*/
        /*int a[] = new int[20], size = 0;
        size=MaxHeap.insert(a, 3,size);
        size=MaxHeap.insert(a, 2,size);
        size=MaxHeap.insert(a, 5,size);
        size=MaxHeap.insert(a, 13,size);
        size=MaxHeap.insert(a, 7,size);
        size=MaxHeap.insert(a, 9,size);
        size=MaxHeap.insert(a, 17,size);
        size=MaxHeap.insert(a, 12,size);
        MaxHeap.adjust(a,size);
        for (int i = 1; i <= size; i++)
            System.out.println(a[i]);*/
        /*MaxHeap heap=new MaxHeap(20);
        heap.push(3);
        heap.push(2);
        heap.push(5);
        heap.push(13);
        heap.push(7);
        heap.push(9);
        heap.push(17);
        heap.push(12);
        heap.print();
        long top = heap.pop();
        System.out.println("top: "+top);
        heap.print();
        top = heap.pop();
        System.out.println("top: "+top);
        heap.print();*/

        /*堆排序（top k，即取最大的前k个数）*/
        /*算法思路：
        * 1.取前k个数建立初始小顶堆heapArray
        * 2.遍历其余的n-k个数，与堆顶元素比较：如果大于堆顶元素，则将堆顶元素替换成此数，同时重新调整小顶堆；否则，保持堆不变*/
        int n=20,k=6;
        long a[]=new long[]{42,17,6,31,5,76,69,66,19,53,4,65,46,90,7,18,37,27,62,25},heapArray[]=new long[k+1];
        /*//建立初始小顶堆heapArray
        for (int i = 0; i < k; i++)
            heapArray[i+1]=a[i];
        MinHeap.adjust(heapArray,k);
        //遍历其余的n-k个数与堆顶元素比较，调整小顶堆
        for (int i = k; i < n; i++){
            if(a[i]>heapArray[1]) {
                heapArray[1] = a[i];
                MinHeap.adjust(heapArray, k);
            }
        }*/
        //建立初始小顶堆heapArray
        for (int i = 0; i < k; i++) {
            heapArray[i + 1] = a[i];
            MinHeap.shift_up(heapArray, i + 1);
        }
        //遍历其余的n-k个数与堆顶元素比较，调整小顶堆
        for (int i = k; i < n; i++){
            if(a[i]>heapArray[1]) {
                heapArray[1] = a[i];
                MinHeap.shift_down(heapArray, k);
            }
        }

        /*链表（单向有序链表）*/
        /*SortedList sortedList = new SortedList();
        sortedList.insert(3);
        sortedList.insert(14);
        sortedList.insert(2);
        sortedList.insert(12);
        sortedList.insert(7);
        Node node = sortedList.find(12);
        sortedList.remove(12);
        sortedList.remove(14);*/

        /*链表（单向有序链表）*/
        /*DoublySortedList sortedList = new DoublySortedList();
        sortedList.insert(3);
        sortedList.insert(14);
        sortedList.insert(2);
        sortedList.insert(12);
        sortedList.insert(7);
        DoublyNode node = sortedList.find(12);
        sortedList.remove(12);
        sortedList.remove(14);*/

        /*链表（普通单向链表）*/
        /*List list = new List();
        list.insert(3);
        list.insert(14);
        list.insert(2);
        list.insert(12);
        list.insert(7);
        Node node = list.find(12);
        list.remove(12);
        list.remove(14);*/

        /*链表（普通双向链表）*/
        /*DoublyList list = new DoublyList();
        list.insert(3);
        list.insert(14);
        list.insert(2);
        list.insert(12);
        list.insert(7);
        DoublyNode node = list.find(12);
        list.remove(12);
        list.remove(14);*/

        /*普通二叉树*/
        /*BinaryTree<Integer> tree=new BinaryTree<>(3);
        tree.insert(2, 3, LeftOrRight.left);//参数：要插入的数，要插入的父结点，要插入的父结点的左结点还是右结点（0表示插入到左结点，1表示插入到右结点）
        tree.insert(5, 3, LeftOrRight.right);
        tree.insert(13, 2, LeftOrRight.left);
        tree.insert(7, 2, LeftOrRight.right);
        tree.insert(9, 5, LeftOrRight.left);
        tree.insert(17, 5, LeftOrRight.right);
        tree.insert(12, 13, LeftOrRight.left);
        tree.insert(12, 13, LeftOrRight.right);//因为是普通二叉树，插入时只考虑要插入的位置是否闲置，而不考虑元素的唯一性，所以元素可能会重复
        tree.insert(14, 13, LeftOrRight.left);
        tree.insert(14, 5, LeftOrRight.left);
        tree.levelOrder();
        tree.preOrder();
        tree.inOrder();
        tree.postOrder();*/

        /*二叉查找树（二叉搜索树或二叉排序树）*/
        /*BinarySearchTree<Integer> tree=new BinarySearchTree<>();
        tree.insert(3);
        tree.insert(1);
        tree.insert(2);
        tree.insert(5);
        tree.insert(13);
        tree.insert(7);
        tree.insert(9);
        tree.insert(17);
        tree.insert(12);
        TreeNode<Integer> node = tree.find(13);
        node = tree.find(14);
        //node = tree.findMin();
        //tree.removeMin();
        tree.remove(5);
        tree.remove(13);
        tree.preOrder();
        tree.inOrder();
        tree.postOrder();
        tree.levelOrder();*/

        /*平衡二叉树（AVL）*/
        /*BalanceBinaryTree<Integer> tree=new BalanceBinaryTree<>();
        tree.insert(3);
        //tree.insert(1);
        tree.insert(2);
        tree.insert(5);
        tree.printTree();
        tree.insert(13);
        tree.printTree();
        tree.insert(7);
        tree.printTree();
        tree.insert(9);
        tree.printTree();
        tree.insert(17);
        tree.printTree();
        tree.insert(12);
        tree.printTree();
        //tree.remove(9);
        tree.remove(13);
        tree.printTree();*/

        /*红黑树*/
        //RedBlackTree<Integer> tree=new RedBlackTree<>();
        /*tree.insert(7);
        tree.insert(3);
        tree.insert(13);
        //tree.insert(2);
        tree.insert(5);
        tree.insert(9);
        tree.insert(17);
        tree.insert(12);
        tree.printTree();
        tree.removeMin();
        tree.printTree();*/
        /*tree.insert(3);
        //tree.insert(1);
        tree.insert(2);
        tree.insert(5);
        tree.insert(13);
        tree.insert(7);
        tree.insert(9);
        tree.insert(17);
        tree.insert(12);
        tree.printTree();
        tree.remove(13);//case2
        tree.remove(9);//case4
        tree.remove(17);//delete red node
        tree.remove(12);//case5
        tree.printTree();*/
        /*tree.insert(3);
        tree.insert(2);
        tree.insert(5);
        tree.insert(13);
        tree.insert(7);
        tree.insert(9);
        tree.insert(17);
        tree.insert(12);
        tree.printTree();
        tree.remove(2);//case4
        tree.printTree();*/
        /*tree.insert(3);
        tree.insert(2);
        tree.insert(5);
        tree.insert(13);
        tree.insert(7);
        tree.insert(9);
        tree.insert(17);
        tree.printTree();
        tree.remove(5);//case3
        tree.printTree();*/
        /*tree.insert(3);
        tree.insert(2);
        tree.insert(5);
        tree.insert(13);
        tree.insert(7);
        tree.insert(9);
        tree.printTree();
        tree.remove(5);//case2
        tree.printTree();*/
        /*tree.insert(3);
        tree.insert(2);
        tree.insert(5);
        tree.insert(13);
        tree.insert(7);
        tree.insert(17);
        tree.printTree();
        tree.remove(5);//case1
        tree.printTree();
        tree.remove(3);//delete root, case4
        tree.printTree();*/

        //BalanceTree<Integer> tree = new BalanceTree<Integer>(4);
        BalanceTree<Integer> tree = new BalanceTree<Integer>(Integer.class,4);
        /*tree.insert(3);
        System.out.println("insert 2");
        tree.insert(2);
        tree.levelOrder();
        System.out.println("insert 5");
        tree.insert(5);
        tree.levelOrder();
        System.out.println("insert 13");
        tree.insert(13);
        tree.levelOrder();
        System.out.println("insert 7");
        tree.insert(7);
        tree.levelOrder();
        System.out.println("insert 9");
        tree.insert(9);
        tree.levelOrder();
        System.out.println("insert 17");
        tree.insert(17);
        tree.levelOrder();
        System.out.println("insert 12");
        tree.insert(12);
        tree.levelOrder();
        System.out.println("insert 1");
        tree.insert(1);
        tree.levelOrder();
        System.out.println("insert 4");
        tree.insert(4);
        tree.levelOrder();
        System.out.println("insert 11");
        tree.insert(11);
        tree.levelOrder();*/
        //tree = new BalanceTree<Integer>(5);
        /*tree = new BalanceTree<Integer>(Integer.class,5);
        tree.insert(3);
        System.out.println("insert 7");
        tree.insert(7);
        tree.levelOrder();
        System.out.println("insert 1");
        tree.insert(1);
        tree.levelOrder();
        System.out.println("insert 14");
        tree.insert(14);
        tree.levelOrder();
        System.out.println("insert 8");
        tree.insert(8);
        tree.levelOrder();
        System.out.println("insert 5");
        tree.insert(5);
        tree.levelOrder();
        System.out.println("insert 11");
        tree.insert(11);
        tree.levelOrder();
        System.out.println("insert 17");
        tree.insert(17);
        tree.levelOrder();
        System.out.println("insert 13");
        tree.insert(13);
        tree.levelOrder();
        System.out.println("insert 6");
        tree.insert(6);
        tree.levelOrder();
        System.out.println("insert 12");
        tree.insert(12);
        tree.levelOrder();
        System.out.println("insert 20");
        tree.insert(20);
        tree.levelOrder();
        System.out.println("insert 23");
        tree.insert(23);
        tree.levelOrder();
        System.out.println("insert 26");
        tree.insert(26);
        tree.levelOrder();
        System.out.println("insert 4");
        tree.insert(4);
        tree.levelOrder();
        System.out.println("insert 16");
        tree.insert(16);
        tree.levelOrder();
        System.out.println("insert 18");
        tree.insert(18);
        tree.levelOrder();
        System.out.println("insert 24");
        tree.insert(24);
        tree.levelOrder();
        System.out.println("insert 25");
        tree.insert(25);
        tree.levelOrder();
        System.out.println("insert 19");
        tree.insert(19);
        tree.levelOrder();
        System.out.println("insert 17");
        tree.insert(17);
        tree.levelOrder();
        System.out.println("insert 15");
        tree.insert(15);
        tree.levelOrder();
        System.out.println("insert 13");
        tree.insert(13);
        tree.levelOrder();
        System.out.println("insert 9");
        tree.insert(9);
        tree.levelOrder();
        System.out.println("insert 10");
        tree.insert(10);
        tree.levelOrder();
        BalanceTreeNode<Integer> node = tree.find(17);
        System.out.println("remove 24");
        tree.remove(24);
        tree.levelOrder();
        System.out.println("remove 19");
        tree.remove(19);
        tree.levelOrder();
        System.out.println("remove 18");
        tree.remove(18);
        tree.levelOrder();
        System.out.println("remove 25");
        tree.remove(25);
        tree.levelOrder();
        System.out.println("remove 16");
        tree.remove(16);
        tree.levelOrder();
        System.out.println("remove 4");
        tree.remove(4);
        tree.levelOrder();*/
        tree = new BalanceTree<Integer>(Integer.class,5);
        for(int i=1;i<=32;i++)
            tree.insert(i);
        tree.levelOrder();
        int m, data;
        Scanner scanner=new Scanner(System.in);
        /*System.out.print("输入b树阶数：");
        m=scanner.nextInt();
        tree = new BalanceTree<Integer>(Integer.class,m);
        while (true)
        {
            System.out.print("插入 ");
            data=scanner.nextInt();
            if (data == -1)break;
            tree.insert(data);
            tree.levelOrder();
        }*/
        while (true)
        {
            System.out.print("删除 ");
            data=scanner.nextInt();
            if (data == -1)break;
            tree.remove(data);
            tree.levelOrder();
        }
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月20日
 *描述: 实现栈的添加、删除功能
 */
/*栈（先进后出）*/
class Stack{
    private int a[];//数组
    private int maxSize;//栈容量
    private int top;//顶栈索引，表示栈实际存储的数量。-1表示没有存入数据，为空栈

    public Stack(int maxSize) {
        this.maxSize = maxSize;
        this.a = new int[this.maxSize];
        this.top = -1;//-1表示空栈
    }

    /*入栈*/
    void push(int value) {
        if (this.top == this.maxSize - 1) {
            System.out.println("stack is full!");
            return;
        }
        a[++top] = value;
    }

    /*返回顶栈，并移除之*/
    int pop() {
        if (this.top == -1) {
            System.out.println("stack is empty!");
            return 0;
        }
        return a[top--];
    }

    /*返回顶栈，但不移除*/
    int peek() {
        if (this.top == -1) {
            System.out.println("stack is empty!");
            return 0;
        }
        return a[top];
    }

    /*返回实际存储数量*/
    int size() {
        return this.top + 1;
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月20日
 *描述: 实现顺序循环队列的添加、删除功能
 */
/*队列（先进先出）*/
//顺序循环队列
// 说明：以顺序结构存储的队列称为顺序队列，因为一般的顺序队列的队满条件是this->end=this->maxSize，会出现假上溢现象
//       为克服假上溢问题，在顺序队列的基础上设计出顺序循环队列（简称为循环队列），即一个首尾相接的环。
//       实际中一般使用顺序循环队列
//       循环队列队满时元素个数为maxSize-1
class RoundQueue{
    private long a[];//数组
    private int maxSize;//队列容量
    private int m_size; //实际存储数量
    private int start;//起始索引
    private int end;//结束索引

    public RoundQueue(int maxSize) {
        this.maxSize = maxSize;
        this.a = new long[this.maxSize];
        this.start = 0;
        this.end = 0;//this->start=this->end表示队列为空,this->start=(this->end+1)%this->maxSize表示队列满
        this.m_size = 0;
    }

    /*加入队列*/
    void push(long value) {
        /*if (this.m_size == this.maxSize) {
            System.out.println("queue is full!");
            return;
        }*/
        if (this.start==(this.end+1)%this.maxSize) {
            System.out.println("queue is full!");
            return;
        }
        a[end] = value;
        end = ++end % maxSize;
        this.m_size++;
    }

    /*返回队列头，并移除之*/
    long pop() {
        /*if (this.m_size == 0) {
            System.out.println("queue is empty!");
            return 0;
        }*/
        if (this.start==this.end) {
            System.out.println("queue is empty!");
            return 0;
        }
        long result=a[start];
        start = ++start % maxSize;
        this.m_size--;
        return result;
    }

    /*返回队列头，但不移除*/
    long peek() {
        if (this.m_size == 0) {
            System.out.println("queue is empty!");
            return 0;
        }
        return a[start];
    }

    /*返回实际存储数量*/
    int size() {
        return this.m_size;
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月21日
 *描述: 实现最大堆、最小堆的添加数据及删除堆顶功能
 */
/*堆*/
class MaxHeap{
    private long a[];//数组
    private int maxSize;//队列容量
    private int m_size; //实际存储数量

    MaxHeap(int maxSize) {
        this.maxSize = maxSize;
        this.a = new long[this.maxSize+1];//元素索引从1开始，a[0]不存元素
        this.m_size = 0;
    }

    void push(int value) {
        this.a[++m_size] = value;
        //adjust();//上浮+下沉
        shift_up();//上浮
    }

    long pop() {
        long top = this.a[1];
        this.a[1] = this.a[this.m_size--];
        shift_down();//下沉
        return top;
    }

    long peek() { return this.a[1]; }

    static int insert(long a[], int value, int size) {
        a[++size] = value;
        return size;
    }
    static void adjust(long a[], int size) {
        //上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
        //下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
        for (int i = size / 2; i > 0; i--)
        {
            a[0] = a[i];//暂存父结点
            int childIndex = i * 2;
            while (childIndex <= size)
            {
                if (childIndex < size && a[childIndex] < a[childIndex + 1])
                    childIndex++;
                if (a[childIndex] < a[0])break;
                else
                {
                    a[childIndex / 2] = a[childIndex];//上浮调整
                    childIndex *= 2;//下沉调整
                }
            }
            a[childIndex / 2] = a[0];
        }
    }

    /*上浮+下沉*/
    void adjust(){
        //上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
        //下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
        for (int i = this.m_size / 2; i > 0; i--)
        {
            this.a[0] = this.a[i];//暂存父结点
            int childIndex = i * 2;
            while (childIndex <= this.m_size)
            {
                if (childIndex < this.m_size && this.a[childIndex] < this.a[childIndex + 1])
                    childIndex++;
                if (this.a[childIndex] < this.a[0])break;
                else
                {
                    this.a[childIndex / 2] = this.a[childIndex];//上浮调整
                    childIndex *= 2;//下沉调整
                }
            }
            this.a[childIndex / 2] = this.a[0];
        }
    }

    /*上浮*/
    void shift_up() {
        int childIndex = this.m_size;
        while (childIndex > 1)
        {
            this.a[0] = this.a[childIndex / 2];//暂存父结点
            if (this.a[childIndex] < this.a[0])
                break;
            else {
                this.a[childIndex / 2] = this.a[childIndex];
                this.a[childIndex] = this.a[0];
                childIndex /= 2;
            }
        }
    }

    /*下沉*/
    void shift_down() {
        int parentIndex = 1, maxIndex;
        while (parentIndex <= this.m_size / 2)
        {
            this.a[0] = this.a[parentIndex];//暂存父结点
            if (parentIndex * 2 < this.m_size && this.a[parentIndex * 2] < this.a[parentIndex * 2 + 1])
                maxIndex = parentIndex * 2 + 1;
            else maxIndex = parentIndex * 2;
            if (this.a[maxIndex] < this.a[0])break;
            else {
                this.a[parentIndex] = this.a[maxIndex];
                this.a[maxIndex] = this.a[0];
            }
            parentIndex = maxIndex;
        }
    }

    int size() { return this.m_size; }

    void print(){
        for (int i = 1; i <= this.m_size; i++)
            System.out.println(this.a[i]);
    }
}
class MinHeap{
    private long a[];//数组
    private int maxSize;//队列容量
    private int m_size; //实际存储数量

    MinHeap(int maxSize) {
        this.maxSize = maxSize;
        this.a = new long[this.maxSize+1];//元素索引从1开始，a[0]不存元素
        this.m_size = 0;
    }

    void push(int value) {
        this.a[++m_size] = value;
        //adjust();//上浮+下沉
        shift_up();//上浮
    }

    long pop() {
        long top = this.a[1];
        this.a[1] = this.a[this.m_size--];
        shift_down();//下沉
        return top;
    }

    long peek() { return this.a[1]; }

    static int insert(long a[], long value, int size) {
        a[++size] = value;
        return size;
    }
    static void adjust(long a[], int size) {
        //上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
        //下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
        for (int i = size / 2; i > 0; i--)
        {
            a[0] = a[i];//暂存父结点
            int childIndex = i * 2;
            while (childIndex <= size)
            {
                if (childIndex < size && a[childIndex] > a[childIndex + 1])
                    childIndex++;
                if (a[childIndex] > a[0])break;
                else
                {
                    a[childIndex / 2] = a[childIndex];//上浮调整
                    childIndex *= 2;//下沉调整
                }
            }
            a[childIndex / 2] = a[0];
        }
    }
    static void shift_up(long a[], int size) {
        int childIndex = size;
        while (childIndex > 1)
        {
            a[0] = a[childIndex / 2];//暂存父结点
            if (a[childIndex] > a[0])
                break;
            else {
                a[childIndex / 2] = a[childIndex];
                a[childIndex] = a[0];
                childIndex /= 2;
            }
        }
    }
    static void shift_down(long a[], int size) {
        int parentIndex = 1, minIndex;
        while (parentIndex <= size / 2)
        {
            a[0] = a[parentIndex];//暂存父结点
            if (parentIndex * 2 < size && a[parentIndex * 2] > a[parentIndex * 2 + 1])
                minIndex = parentIndex * 2 + 1;
            else minIndex = parentIndex * 2;
            if (a[minIndex] > a[0])break;
            else {
                a[parentIndex] = a[minIndex];
                a[minIndex] = a[0];
            }
            parentIndex = minIndex;
        }
    }

    /*上浮+下沉*/
    void adjust(){
        //上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
        //下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
        for (int i = this.m_size / 2; i > 0; i--)
        {
            this.a[0] = this.a[i];//暂存父结点
            int childIndex = i * 2;
            while (childIndex <= this.m_size)
            {
                if (childIndex < this.m_size && this.a[childIndex] > this.a[childIndex + 1])
                    childIndex++;
                if (this.a[childIndex] > this.a[0])break;
                else
                {
                    this.a[childIndex / 2] = this.a[childIndex];//上浮调整
                    childIndex *= 2;//下沉调整
                }
            }
            this.a[childIndex / 2] = this.a[0];
        }
    }

    /*上浮*/
    void shift_up() {
        int childIndex = this.m_size;
        while (childIndex > 1)
        {
            this.a[0] = this.a[childIndex / 2];//暂存父结点
            if (this.a[childIndex] > this.a[0])
                break;
            else {
                this.a[childIndex / 2] = this.a[childIndex];
                this.a[childIndex] = this.a[0];
                childIndex /= 2;
            }
        }
    }

    /*下沉*/
    void shift_down() {
        int parentIndex = 1, minIndex;
        while (parentIndex <= this.m_size / 2)
        {
            this.a[0] = this.a[parentIndex];//暂存父结点
            if (parentIndex * 2 < this.m_size && this.a[parentIndex * 2] > this.a[parentIndex * 2 + 1])
                minIndex = parentIndex * 2 + 1;
            else minIndex = parentIndex * 2;
            if (this.a[minIndex] > this.a[0])break;
            else {
                this.a[parentIndex] = this.a[minIndex];
                this.a[minIndex] = this.a[0];
            }
            parentIndex = minIndex;
        }
    }

    int size() { return this.m_size; }

    void print(){
        for (int i = 1; i <= this.m_size; i++)
            System.out.println(this.a[i]);
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月22日
 *描述: 实现优先队列的添加数据及删除优先值功能
 */
/*优先队列（数组实现）*/
//优先队列又称优先级队列，是一种有序队列，按大小排好序的队列，可用数组或堆来实现。
//因为上面已经写了堆的实现，下面展示的是用数组实现最大优先队列。
//如果用数组实现，按大小顺序依次存储，a[0]是优先级最低的，a[size-1]是优先级最高的
class MaxPriorityQueue{
    private long a[];//数组
    private int maxSize;//队列容量
    private int m_size; //实际存储数量

    public MaxPriorityQueue(int maxSize) {
        this.maxSize = maxSize;
        this.a = new long[this.maxSize];
        this.m_size = 0;
    }

    void push(long value) {
        if (this.m_size == this.maxSize) {
            System.out.println("heap is full!");
            return;
        }
        if(m_size==0) {
            a[m_size++] = value;
            return;
        }
        //从优先级别高的数开始比较，如果被比较数大于插入数，则被比较数往后移一位。也就是说，让最大数保持在最末位置，插入数后不打乱原来顺序
        int index=m_size - 1;
        for (int i = m_size - 1; i >= 0; i--) {
            if (this.a[i] > value) {
                a[i + 1] = a[i];
                index=i;
            }
            else {
                index=i+1;
                break;
            }
        }
        a[index] = value;
        this.m_size++;
    }

    //返回队列头，并移除之
    long pop() {
        if (this.m_size == 0) {
            System.out.println("heap is empty!");
            return 0;
        }
        return a[--m_size];
    }

    //返回队列头，但不移除
    long peek() {
        if (this.m_size == 0) {
            System.out.println("heap is empty!");
            return 0;
        }
        return a[m_size - 1];
    }

    int size() {
        return this.m_size;
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月22日
 *描述: 实现单向有序链表的插入、删除及查找功能
 */
/*链表（单向有序链表）*/
class Node {
    int data;
    Node next;

    Node() {
        this.data = 0;
        this.next = null;
    }

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}
class SortedList{
    private Node first=null;//起始节点
    private int m_size=0;//节点数量

    public void insert(int value) {
        Node newNode = new Node(value);
        Node previous = null;
        Node current = this.first;
        if (this.m_size == 0)this.first = newNode;
        else
        {
            /*从头开始比较，前项值比其小，后项值比其大*/
            while (current . data < value) {
                previous = current;
                //如果到链表末端被比较值还比插入值小，则将其插入末端
                if (current . next == null) {
                    current . next = newNode;
                    break;
                }
                current = current . next;
            }
            //如果链表起始节点值就比插入值大，则将其插入首端
            if (previous == null) {
			/*previous = this.first;
			this.first = *newLink;
			this.first.next = &previous;*/
                newNode . next = this.first;
                this.first = newNode;
            }
            //否则将其插入中间，前项的next指向newLink，newLink的next指向后项
            else if (current != this.first && current . data > value)
            {
                previous . next = newNode;
                newNode . next = current;
            }
        }
        this.m_size++;
    }

    /*移除*/
    void remove(int value){
        Node previous = this.first;
        Node current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return;//表示没有等于目标值的节点
            previous = current;
            current = current.next;
        }
        /*删除*/
        if (current == this.first)first = first.next;//如果起始节点值就等于目标值，则删除起始节点（没有指向起始节点的指针）
        else previous.next = current.next;//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
        this.m_size--;
    }

    /*查找*/
    Node find(int value){
        Node current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return null;//表示没有等于目标值的节点
            current = current.next;
        }
        return current;
    }

    /*数量*/
    int size(){
        return this.m_size;
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月22日
 *描述: 实现双向有序链表的插入、删除及查找功能
 */
/*链表（双向有序链表）*/
class DoublyNode {
    int data;
    DoublyNode previous;
    DoublyNode next;

    DoublyNode(int data) {
        this.data = data;
        this.previous = null;
        this.next = null;
    }
};
class DoublySortedList {
    private DoublyNode first = null;//起始节点
    private DoublyNode last = null;//终止节点
    private int m_size = 0;//节点数量

    public void insert(int value){
        DoublyNode newNode = new DoublyNode(value);
        DoublyNode previous = null;
        DoublyNode current = this.first;
        if (this.m_size == 0) {
            this.first = newNode;
            this.last = newNode;
        }
        else
        {
            /*从头开始比较，前项值比其小，后项值比其大*/
            while (current.data < value)
            {
                previous = current;
                //如果到链表末端被比较值还比插入值小，则将其插入末端
                if (current.next == null) {
                    current.next = newNode;
                    newNode.previous = current;
                    this.last = newNode;
                    break;
                }
                current = current.next;
            }
            //如果链表起始节点值就比插入值大，则将其插入首端
            if (previous == null) {
                this.first.previous = newNode;
                newNode.next = this.first;
                this.first = newNode;
            }
            //否则将其插入中间，前项的next指向newLink，newLink的next指向后项
            else if (current != this.first && current.data > value)
            {
                previous.next = newNode;
                newNode.previous = previous;
                newNode.next = current;
                current.previous = newNode;
            }
        }
        this.m_size++;
    }

    /*移除*/
    public void remove(int value){
        DoublyNode previous = this.first;
        DoublyNode current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return;//表示没有等于目标值的节点
            previous = current;
            current = current.next;
        }
        /*删除*/
        if (current == this.first) {//如果起始节点值就等于目标值，则删除起始节点
            this.first.next.previous = null;
            this.first = this.first.next;
        }
        else if (current == this.last) {//如果末尾节点值就等于目标值，则删除末尾节点
            this.last.previous.next = null;
            this.last = this.last.previous;
        }
        else {//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
            previous.next = current.next;
            current.next.previous = previous;
        }
        this.m_size--;
    }

    /*查找*/
    public DoublyNode find(int value){
        DoublyNode current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return null;//表示没有等于目标值的节点
            current = current.next;
        }
        return current;
    }

    /*数量*/
    public int size(){
        return this.m_size;
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月23日
 *描述: 实现普通单向链表的添加、删除及查找功能
 */
/*链表（普通单向链表）*/
class List {
    private Node first = null;//起始节点
    private int m_size = 0;//节点数量

    public void insertFirst(int value) {
        Node newNode = new Node(value);
        this.first.next = this.first;//*this.first.next = this.first;
        this.first = newNode;
        this.m_size++;
    }

    /*删除起始节点*/
    Node removeFirst(){
        Node t = this.first;
        this.first = this.first.next;
        this.m_size--;
        return t;
    }

    /*插入*/
    void insert(int value){
        Node newNode = new Node(value);
        Node previous = null;
        Node current = this.first;
        if (this.m_size == 0)this.first = newNode;
        else
        {
            while (current.next != null)current = current.next;
            current.next = newNode;
        }
        this.m_size++;
    }

    /*移除*/
    void remove(int value){
        Node previous = this.first;
        Node current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return;//表示没有等于目标值的节点
            previous = current;
            current = current.next;
        }
        /*删除*/
        if (current == this.first)first = first.next;//如果起始节点值就等于目标值，则删除起始节点（没有指向起始节点的指针）
        else previous.next = current.next;//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
        this.m_size--;
    }

    /*查找*/
    Node find(int value){
        Node current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return null;//表示没有等于目标值的节点
            current = current.next;
        }
        return current;
    }

    /*数量*/
    int size(){
        return this.m_size;
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月23日
 *描述: 实现普通双向链表的添加、删除及查找功能
 */
/*链表（普通双向链表）*/
class DoublyList {
    private DoublyNode first = null;//起始节点
    private DoublyNode last = null;//终止节点
    private int m_size = 0;//节点数量

    public void insertFirst(int value){
        DoublyNode newNode = new DoublyNode(value);
        if (this.m_size == 0) {
            this.first = newNode;
            this.last = newNode;
            this.m_size++;
            return;
        }
        /*重建原起始节点的连接*/
        this.first.previous = newNode;
        /*起始节点指向新节点*/
        newNode.next = this.first;
        this.first = newNode;
        this.m_size++;
    }

    /*删除起始节点*/
    public DoublyNode removeFirst(){
        DoublyNode t = this.first;
        this.first = this.first.next;
        this.first.previous = null;
        this.m_size--;
        return t;
    }

    /*插入终止节点*/
    public void insertLast(int value){
        DoublyNode newNode = new DoublyNode(value);
        this.last.next = newNode;
        newNode.previous = this.last;
        this.last = newNode;
        this.m_size++;
    }

    /*删除终止节点*/
    public DoublyNode removeLast(){
        DoublyNode t = this.last;
        this.last = this.last.previous;
        this.last.next = null;
        this.m_size--;
        return t;
    }

    /*插入*/
    public void insert(int value){
        DoublyNode newNode = new DoublyNode(value);
        DoublyNode previous = null;
        DoublyNode current = this.first;
        if (this.m_size == 0) {
            this.first = newNode;
            this.last = newNode;
        }
        else
        {
            while (current.next != null)current = current.next;

            current.next = newNode;
            newNode.previous = current;
            this.last = newNode;
        }
        this.m_size++;
    }

    /*移除*/
    public void remove(int value){
        DoublyNode previous = this.first;
        DoublyNode current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return;//表示没有等于目标值的节点
            previous = current;
            current = current.next;
        }
        /*删除*/
        if (current == this.first) {//如果起始节点值就等于目标值，则删除起始节点
            this.first.next.previous = null;
            this.first = this.first.next;
        }
        else if (current == this.last) {//如果末尾节点值就等于目标值，则删除末尾节点
            this.last.previous.next = null;
            this.last = this.last.previous;
        }
        else {//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
            previous.next = current.next;
            current.next.previous = previous;
        }
        this.m_size--;
    }

    /*查找*/
    public DoublyNode find(int value){
        DoublyNode current = this.first;
        /*从头开始比较，如果不等于目标值，一直链接下去*/
        while (current.data != value)
        {
            if (current.next == null)return null;//表示没有等于目标值的节点
            current = current.next;
        }
        return current;
    }

    /*数量*/
    public int size(){
        return this.m_size;
    }
};

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月24日
 *描述: 实现一棵普通二叉树的构建及遍历
 */
/*普通二叉树*/
class TreeNode<Type> {
    Type data;
    TreeNode<Type> leftchild, rightchild;
};
enum LeftOrRight {
    left,
    right
};
class BinaryTree<Type> {
    private TreeNode<Type> root;
    private int m_size;

    BinaryTree() {root=null;m_size=0;}
    BinaryTree(Type data){
        root=null;m_size=0;
        TreeNode<Type> newNode = new TreeNode<Type>();
        newNode.data = data;
        this.root = newNode;
        this.m_size++;
    }
    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        release(root);
    }

    private void release(TreeNode<Type> treeNode) {
        if (null != treeNode) {
            release(treeNode.leftchild);
            release(treeNode.rightchild);
            treeNode=null;
        }
    }
    private boolean insertNode(Type data, Type parent, LeftOrRight leftOrRight, TreeNode<Type> treeNode) {
        if (null == treeNode)return false;
        if (treeNode.data == parent) {
            TreeNode<Type> newNode = new TreeNode<Type>();
            newNode.data = data;
            if (leftOrRight == LeftOrRight.left&&treeNode.leftchild == null) {
                treeNode.leftchild = newNode;
                return true;
            }
            else if (leftOrRight == LeftOrRight.right&&treeNode.rightchild == null) {
                treeNode.rightchild = newNode;
                return true;
            }
            else return false;
        }
        if (insertNode(data, parent, leftOrRight, treeNode.leftchild) || insertNode(data, parent, leftOrRight, treeNode.rightchild))
            return true;
        else return false;
    }
    private void preOrderTraverse(TreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            System.out.print(treeNode.data + " ");
            preOrderTraverse(treeNode.leftchild);
            preOrderTraverse(treeNode.rightchild);
        }
    }
    private void inOrderTraverse(TreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            inOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data + " ");
            inOrderTraverse(treeNode.rightchild);
        }
    }
    private void postOrderTraverse(TreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            postOrderTraverse(treeNode.rightchild);
            postOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data + " ");
        }
    }
    /*层次遍历，非递归*/
    private void levelOrderTraverse(TreeNode<Type> root) {
        Queue<TreeNode<Type>> queue=new LinkedList<>();//辅助队列，用于层次遍历
        if (root == null) {
            return;
        }
        queue.add(root);
        TreeNode<Type> temp = null;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.poll();
                System.out.print(temp.data + " ");
                if (temp.leftchild != null) {
                    queue.add(temp.leftchild);
                }
                if (temp.rightchild != null) {
                    queue.add(temp.rightchild);
                }
            }
            System.out.print('\n');//换行
        }
    }

    public void insertRoot(Type data) {
        TreeNode<Type> newNode = new TreeNode<Type>();
        newNode.data = data;
        this.root = newNode;
        this.m_size++;
    }
    public void insert(Type data, Type parent, LeftOrRight leftOrRight) { if (!insertNode(data, parent, leftOrRight, root))System.out.println("insert failed");}
    public void preOrder() {
        preOrderTraverse(root);
        System.out.print('\n');
    }
    public void inOrder() {
        inOrderTraverse(root);
        System.out.print('\n');
    }
    public void postOrder() {
        postOrderTraverse(root);
        System.out.print('\n');
    }
    public void levelOrder() { levelOrderTraverse(root); }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月24日
 *描述: 实现二叉查找树的插入、删除及查找功能
 */
/*二叉查找树（二叉搜索树或二叉排序树）*/
class BinarySearchTree<Type extends Comparable> {
    private TreeNode<Type> root;
    private int m_size;

    BinarySearchTree() {root=null;m_size=0;}
    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        release(root);
    }

    private void release(TreeNode<Type> treeNode) {
        if (null != treeNode) {
            release(treeNode.leftchild);
            release(treeNode.rightchild);
            treeNode=null;
        }
    }
    private TreeNode<Type> insertNode(TreeNode<Type> parentNode,Type data) {
        if (null == parentNode) {
            parentNode = new TreeNode<Type>();
            parentNode.data = data;
            m_size++;
            return parentNode;
        }
        //"parentNode.data > data"提示错误Operator '>' cannot be applied to 'Type', 'Type'"
        //java中泛型不能直接使用==、>、<符号来比较大小，而需要将Type继承于Comparable，然后使用使用compareTo方法比较大小
        //Interger、Float等类型使用compareTo方法比较大小时，如果该对象小于指定对象，返回负整数；如果该对象等于指定对象，返回零；如果该对象大于指定对象，则返回正整数
        if (parentNode.data.compareTo(data)>0)
            parentNode.leftchild=insertNode(parentNode.leftchild, data);
        else if (parentNode.data.compareTo(data)<0)
            parentNode.rightchild=insertNode(parentNode.rightchild, data);
        return parentNode;
    }
    private TreeNode<Type> findNode(TreeNode<Type> parentNode, Type data) {
        if (null == parentNode) return null;
        if (parentNode.data.compareTo(data)==0) return parentNode;
        if (parentNode.data.compareTo(data)>0)
            return findNode(parentNode.leftchild, data);
        else return findNode(parentNode.rightchild, data);
    }
    private TreeNode<Type> removeNode(TreeNode<Type> parentNode, Type data) {
        if (null == parentNode) return null;
        if (parentNode.data == data) {
            if (parentNode.leftchild == null&&parentNode.rightchild == null)
                parentNode=null;
            else if (parentNode.leftchild != null&&parentNode.rightchild == null)
                parentNode = parentNode.leftchild;
            else if (parentNode.leftchild == null&&parentNode.rightchild != null)
                parentNode = parentNode.rightchild;
            else if (parentNode.leftchild != null&&parentNode.rightchild != null) {
                parentNode.data = findMinNode(parentNode.rightchild).data;
                parentNode.rightchild=removeMinNode(parentNode.rightchild);
            }
            return parentNode;
        }
        if (parentNode.data.compareTo(data)>0)
            parentNode.leftchild=removeNode(parentNode.leftchild, data);
        else if (parentNode.data.compareTo(data)<0)
            parentNode.rightchild=removeNode(parentNode.rightchild, data);
        return parentNode;
    }
    private TreeNode<Type> findMinNode(TreeNode<Type> parentNode) {
        while (null != parentNode.leftchild)
            parentNode=parentNode.leftchild;
        return parentNode;
    }
    private TreeNode<Type> removeMinNode(TreeNode<Type> parentNode) {
        if (null == parentNode.leftchild)
            return parentNode.rightchild;
        parentNode.leftchild=removeMinNode(parentNode.leftchild);
        return parentNode;
    }
    private void preOrderTraverse(TreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            System.out.print(treeNode.data + " ");
            preOrderTraverse(treeNode.leftchild);
            preOrderTraverse(treeNode.rightchild);
        }
    }
    private void inOrderTraverse(TreeNode<Type> treeNode){
        if (null == treeNode)return;
        else
        {
            inOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data + " ");
            inOrderTraverse(treeNode.rightchild);
        }
    }
    private void postOrderTraverse(TreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            postOrderTraverse(treeNode.rightchild);
            postOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data + " ");
        }
    }
    /*层次遍历，非递归*/
    private void levelOrderTraverse(TreeNode<Type> root) {
        Queue<TreeNode<Type>> queue=new LinkedList<>();//辅助队列，用于层次遍历
        if (root == null) {
            return;
        }
        queue.add(root);
        TreeNode<Type> temp = null;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.poll();
                System.out.print(temp.data + " ");
                if (temp.leftchild != null) {
                    queue.add(temp.leftchild);
                }
                if (temp.rightchild != null) {
                    queue.add(temp.rightchild);
                }
            }
            System.out.print("\n");//换行
        }
    }

    public void insert(Type data) {
        root=insertNode(root, data);
    }
    public TreeNode<Type> find(Type data) { return findNode(root, data); }
    public void remove(Type data) { root=removeNode(root, data); }
    public TreeNode<Type> findMin() { return findMinNode(root); }
    public void removeMin() { root=removeMinNode(root); }
    public void preOrder() {
        preOrderTraverse(root);
        System.out.print("\n");
    }
    public void inOrder() {
        inOrderTraverse(root);
        System.out.print("\n");
    }
    public void postOrder() {
        postOrderTraverse(root);
        System.out.print("\n");
    }
    public void levelOrder() { levelOrderTraverse(root); }
};

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月26日
 *描述: 实现平衡二叉树的插入、删除、查找及打印功能
 */
/*平衡二叉树（AVL）*/
class BalanceBinaryTreeNode<Type> {
    Type data;
    int level;
    BalanceBinaryTreeNode<Type> leftchild, rightchild;
}
class BalanceBinaryTree<Type extends Comparable> {
    private BalanceBinaryTreeNode<Type> root;
    private int m_size;
    private int m_level;

    BalanceBinaryTree() {root=null;m_size=0;}
    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        release(root);
    }

    private void release(BalanceBinaryTreeNode<Type> treeNode) {
        if (null != treeNode) {
            release(treeNode.leftchild);
            release(treeNode.rightchild);
            treeNode=null;
        }
    }
    private int height(BalanceBinaryTreeNode<Type> node) {
        return (null == node) ? 0 : node.level;
    }
    /*针对LL型，右旋
            7
          /  \
         3   9
       / \
      2  5
      -->
        3
      /  \
     2   7
       / \
      5  9
     */
    private BalanceBinaryTreeNode<Type> rightRotate(BalanceBinaryTreeNode<Type> node) {
        /*将左子节点设为新父节点result*/
        BalanceBinaryTreeNode<Type> result = node.leftchild;

        /*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
        //先将右子结点暂存，然后替换
		/*BalenceTreeNode<Type> temp = result.rightchild;
		result.rightchild = node;
		node.leftchild = temp;*/
        //更简便替换方法
        node.leftchild = result.rightchild;
        result.rightchild = node;

        /*更新高度*/
        node.level = Math.max(height(node.leftchild), height(node.rightchild)) + 1;
        result.level = Math.max(height(result.leftchild), height(result.rightchild)) + 1;

        return result;
    }
    /*针对RR型，左旋
        3
      /  \
     2   7
       / \
      5  9
      -->
            7
          /  \
         3   9
       / \
      2  5
    */
    private BalanceBinaryTreeNode<Type> leftRotate(BalanceBinaryTreeNode<Type> node) {
        /*将右子节点设为新父节点result*/
        BalanceBinaryTreeNode<Type> result = node.rightchild;

        /*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
        //先将左子结点暂存，然后替换
		/*BalenceTreeNode<Type> temp = result.leftchild;
		result.leftchild = node;
		node.rightchild = temp;*/
        //更简便替换方法
        node.rightchild = result.leftchild;
        result.leftchild = node;

        /*更新高度*/
        node.level = Math.max(height(node.leftchild), height(node.rightchild)) + 1;
        result.level = Math.max(height(result.leftchild), height(result.rightchild)) + 1;

        return result;
    }
    private BalanceBinaryTreeNode<Type> insertNode(BalanceBinaryTreeNode<Type>  parentNode, Type data) {
        if (null == parentNode) {
            parentNode = new BalanceBinaryTreeNode<Type>();
            parentNode.data = data;
            parentNode.level = 1;
            m_size++;
            return parentNode;
        }
        else if (parentNode.data.compareTo(data)>0) {
            parentNode.leftchild=insertNode(parentNode.leftchild, data);
        }
        else if (parentNode.data.compareTo(data)<0) {
            parentNode.rightchild=insertNode(parentNode.rightchild, data);
        }

        parentNode.level = Math.max(height(parentNode.leftchild), height(parentNode.rightchild)) + 1;

        //计算平衡因子，即左右高度差
        int balenceFactor= (null == parentNode) ? 0 : height(parentNode.leftchild) - height(parentNode.rightchild);
        /*根据平衡因子调整左右子结点*/
        if (balenceFactor > 1 && parentNode.leftchild.data.compareTo(data) > 0)parentNode=rightRotate(parentNode);
        else if (balenceFactor > 1 && parentNode.leftchild.data.compareTo(data) < 0) {/*针对LR型平衡，先左旋，后右旋*/
            parentNode.leftchild=leftRotate(parentNode.leftchild);
            parentNode=rightRotate(parentNode);
        }
        else if (balenceFactor < -1 && parentNode.rightchild.data.compareTo(data) < 0)parentNode=leftRotate(parentNode);
        else if (balenceFactor < -1 && parentNode.rightchild.data.compareTo(data) > 0) {/*针对RL型平衡，先右旋，后左旋*/
            parentNode.rightchild=rightRotate(parentNode.rightchild);
            parentNode=leftRotate(parentNode);
        }
        return parentNode;
    }
    private BalanceBinaryTreeNode<Type> findNode(BalanceBinaryTreeNode<Type>  parentNode, Type data) {
        if (null == parentNode) return null;
        if (parentNode.data.compareTo(data) == 0) return parentNode;
        if (parentNode.data.compareTo(data) > 0)
            return findNode(parentNode.leftchild, data);
        else return findNode(parentNode.rightchild, data);
    }
    private BalanceBinaryTreeNode<Type> removeNode(BalanceBinaryTreeNode<Type>  parentNode, Type data) {
        if (null == parentNode) return null;
        if (parentNode.data == data) {
            if (parentNode.leftchild == null&&parentNode.rightchild == null)
                parentNode=null;
            else if (parentNode.leftchild != null&&parentNode.rightchild == null)
                parentNode = parentNode.leftchild;
            else if (parentNode.leftchild == null&&parentNode.rightchild != null)
                parentNode = parentNode.rightchild;
            else if (parentNode.leftchild != null&&parentNode.rightchild != null) {
                if(height(parentNode.leftchild)<height(parentNode.rightchild)) {
                    parentNode.data = findMinNode(parentNode.rightchild).data;
                    parentNode.rightchild = removeMinNode(parentNode.rightchild);
                }else {
                    parentNode.data = findMaxNode(parentNode.leftchild).data;
                    parentNode.leftchild = removeMaxNode(parentNode.leftchild);
                }
            }
            return parentNode;
        }
        if (parentNode.data.compareTo(data) > 0)
            parentNode.leftchild=removeNode(parentNode.leftchild, data);
        else if (parentNode.data.compareTo(data) < 0)
            parentNode.rightchild=removeNode(parentNode.rightchild, data);
        return parentNode;
    }
    private BalanceBinaryTreeNode<Type> findMinNode(BalanceBinaryTreeNode<Type> parentNode) {
        while (null != parentNode.leftchild)
            parentNode=parentNode.leftchild;
        return parentNode;
    }
    private BalanceBinaryTreeNode<Type> removeMinNode(BalanceBinaryTreeNode<Type> parentNode) {
        if (null == parentNode.leftchild)
            return parentNode.rightchild;
        parentNode.leftchild=removeMinNode(parentNode.leftchild);
        return parentNode;
    }
    private BalanceBinaryTreeNode<Type> findMaxNode(BalanceBinaryTreeNode<Type> parentNode) {
        while (null != parentNode.rightchild)
            parentNode=parentNode.rightchild;
        return parentNode;
    }
    private BalanceBinaryTreeNode<Type> removeMaxNode(BalanceBinaryTreeNode<Type> parentNode) {
        if (null == parentNode.rightchild)
            return parentNode.leftchild;
        parentNode.rightchild=removeMinNode(parentNode.rightchild);
        return parentNode;
    }
    private void preOrderTraverse(BalanceBinaryTreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            System.out.print(treeNode.data+" ");
            preOrderTraverse(treeNode.leftchild);
            preOrderTraverse(treeNode.rightchild);
        }
    }
    private void inOrderTraverse(BalanceBinaryTreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            inOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data+" ");
            inOrderTraverse(treeNode.rightchild);
        }
    }
    private void postOrderTraverse(BalanceBinaryTreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            postOrderTraverse(treeNode.rightchild);
            postOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data+" ");
        }
    }
    /*层次遍历，非递归*/
    private void levelOrderTraverse(BalanceBinaryTreeNode<Type> root) {
        Queue<BalanceBinaryTreeNode<Type>> queue=new LinkedList<>();//辅助队列，用于层次遍历
        if (root == null) {
            return;
        }
        queue.add(root);
        BalanceBinaryTreeNode<Type> temp = null;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.poll();
                System.out.print(temp.data+" ");
                if (temp.leftchild != null) {
                    queue.add(temp.leftchild);
                }
                if (temp.rightchild != null) {
                    queue.add(temp.rightchild);
                }
            }
            System.out.print("\n");//换行
        }
    }
    /*将树结点以矩阵形式写入，最后打印矩阵即可形象地将树展示出来。
    因为树的结点位置与其父结点位置相关，所以递归参数时需要传递父结点的位置。*/
    private void writeArray(BalanceBinaryTreeNode<Type> node, String[][] array, int row, int col) {
        if (root == null)return;
        array[row][col] = node.data.toString();
        int level = row / 2 + 1;
        if (level == root.level)return;

        /*递归左右子结点*/
        //int gap = pow(2, root.level - level - 1)  3;//3,6,12,...
        int gap = (2 << (root.level - level - 1));//2,4,8,...
        if (node.leftchild != null) {
            array[row + 1][col - gap / 2] = "/";
            writeArray(node.leftchild, array, row + 2, col - gap);
        }
        if (node.rightchild != null) {
            array[row + 1][col + gap / 2] = "\\";
            writeArray(node.rightchild, array, row + 2, col + gap);
        }
    }

    public void insert(Type data) { root=insertNode(root, data); }
    public BalanceBinaryTreeNode<Type> find(Type data) { return findNode(root, data); }
    public void remove(Type data) { root=removeNode(root, data); }
    public BalanceBinaryTreeNode<Type> findMin() { return findMinNode(root); }
    public void removeMin() { root=removeMinNode(root); }
    public BalanceBinaryTreeNode<Type> findMax() { return findMaxNode(root); }
    public void removeMax() { root=removeMaxNode(root); }
    public void preOrder() {
        preOrderTraverse(root);
        System.out.print("\n");
    }
    public void inOrder() {
        inOrderTraverse(root);
        System.out.print("\n");
    }
    public void postOrder() {
        postOrderTraverse(root);
        System.out.print("\n");
    }
    public void levelOrder() { levelOrderTraverse(root); }
    public void printTree() {
        //int width = (pow(2, root.level - 1) - 1)  6 + 1;//((2 << (m_height - 2)) - 1)  6 + 1;//0+1,3*2+1,9*2+1,21*2+1,...,6*(pow(2,level-1)-1)+1
        int width = (int)(Math.pow(2, root.level - 1) - 1) * 4 + 1;//((2 << (m_height - 2)) - 1)  4 + 1;//0+1,2*2+1,6*2+1,14*2+1,...,4*(pow(2,level-1)-1)+1
        //string array[2  root.level - 1][width];
        String[][] array = new String[2 * root.level - 1][];
        for (int i = 0; i < 2 * root.level - 1; i++) {
            array[i] = new String[width];
            for (int j = 0; j < width; j++) {
                array[i][j] = " ";
            }
        }
        int a = 2 << (root.level - 2);
        //writeArray(root, array, 0, (pow(2, root.level - 1) - 1)  3);//(pow(2, root.level - 1) - 1)  3;
        writeArray(root, array, 0, (int)(Math.pow(2, root.level - 1) - 1) * 2);//(pow(2, root.level - 1) - 1)  2;
        /*打印矩阵*/
        for (int i = 0; i < 2 * root.level - 1; i++) {
            for (int j = 0; j < width; j++) {
                System.out.print(array[i][j]);
            }
            System.out.print("\n");//换行
        }
    }
}

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月27日
 *描述: 实现红黑树的插入、删除、查找及打印功能
 */
/*红黑树*/
/*1.每个结点或者是红色的，或者是黑色的
* 2 根结点是黑色的
* 3 每个叶子结点（红黑树中叶子结点指NIL结点）是黑色的
* 4 如果一个结点是红色的，那么他的孩子都是黑色的
* 5 从任意一个节点到NIL叶子结点经过的黑色结点数是一样的*/
enum Color {
    red,
    black
}
class RedBlackTreeNode<Type> {
    Type data;
    Color color;//true表示红，false表示黑
    RedBlackTreeNode<Type> leftchild, rightchild,parent;

    RedBlackTreeNode(){
        color=Color.red;
        leftchild=null;
        rightchild=null;
        parent=null;
    }
}
class RedBlackTree<Type extends Comparable> {
    private RedBlackTreeNode<Type> root;
    private int m_size;
    private int m_height;

    RedBlackTree() {root=null;m_size=0;}
    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        release(root);
    }

    private void release(RedBlackTreeNode<Type> treeNode) {
        if (null != treeNode) {
            release(treeNode.leftchild);
            release(treeNode.rightchild);
            treeNode=null;
        }
    }
    private int height(RedBlackTreeNode<Type> node) {
        return (null == node) ? 0 : Math.max(height(node.leftchild), height(node.rightchild)) + 1;
    }
    private boolean isRed(RedBlackTreeNode<Type> node) {
        return (null == node||Color.black==node.color) ? false : true;
    }
    private RedBlackTreeNode<Type> parent(RedBlackTreeNode<Type> root,RedBlackTreeNode<Type> node){
        if(null==root)return null;
        if(root.leftchild==node)return root.leftchild;
        if(root.rightchild==node)return root.rightchild;
        RedBlackTreeNode<Type> resultLeft=parent(root.leftchild,node);
        RedBlackTreeNode<Type> resultRight=parent(root.rightchild,node);
        return resultLeft!=null ? resultLeft:resultRight;
    }
    private void flipColor(RedBlackTreeNode<Type> node) {
        node.color = Color.red;
        node.leftchild.color = Color.black;
        node.rightchild.color = Color.black;
    }
    private void rightRotate(RedBlackTreeNode<Type> node) {
        /*将左子节点设为新父节点result*/
        RedBlackTreeNode<Type> result = node.leftchild;
        result.parent = node.parent;
        if(node==root)
            root = result;
        else {
            if (node == node.parent.leftchild)
                node.parent.leftchild = result;
            else node.parent.rightchild = result;
        }

        /*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
        node.leftchild = result.rightchild;
        if(null!=result.rightchild)result.rightchild.parent = node;
        result.rightchild = node;
        node.parent = result;

        /*换色*/
        /*result.color = node.color;
        node.color = Color.red;*/
        Color color=result.color;
        result.color = node.color;
        node.color = color;
    }
    private void leftRotate(RedBlackTreeNode<Type> node) {
        /*将右子节点设为新父节点result*/
        RedBlackTreeNode<Type> result = node.rightchild;
        result.parent = node.parent;
        if(node==root)
            root = result;
        else {
            if (node == node.parent.leftchild)
                node.parent.leftchild = result;
            else node.parent.rightchild = result;
        }

        /*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
        node.rightchild = result.leftchild;
        if(null!=result.leftchild)result.leftchild.parent = node;
        result.leftchild = node;
        node.parent = result;

        /*换色*/
        /*result.color = node.color;
        node.color = Color.red;*/
        Color color=result.color;
        result.color = node.color;
        node.color = color;
    }
    private RedBlackTreeNode<Type> insertNode(RedBlackTreeNode<Type> parentNode, Type data) {
        if (null == parentNode) {
            parentNode = new RedBlackTreeNode<Type>();
            parentNode.data = data;
            m_size++;
            return parentNode;
        }
        else if (parentNode.data.compareTo(data) > 0) {
            parentNode.leftchild=insertNode(parentNode.leftchild, data);
        }
        else if (parentNode.data.compareTo(data) < 0) {
            parentNode.rightchild=insertNode(parentNode.rightchild, data);
        }

        /*根据红黑树规则调整左右子结点*/
        /*左倾红黑树*/
		/*
		1.如果左子结点为黑，右子结点为红，则左旋；（由2-3树衍变成红黑树的左倾规则）
		2.如果左子结点为红，且左子结点的左子结点也为红，则右旋；（红黑树性质4）
		3.如果左右子结点均为红，则颜色反转*/
		/*if(!isRed(parentNode.leftchild) && isRed(parentNode.rightchild))parentNode=leftRotate(parentNode);//如果左子结点为黑，右子结点为红，则左旋
		if (isRed(parentNode.leftchild) && isRed(parentNode.leftchild.leftchild))parentNode=rightRotate(parentNode);//如果左子结点为红，且左子结点的左子结点也为红，则右旋
		if (isRed(parentNode.leftchild) && isRed(parentNode.rightchild))flipColor(parentNode);//如果左右子结点均为红，则颜色反转*/
        /*改进版红黑树（作者：习佳威）*/
		/*
		1.如果左右子结点均为红，则颜色反转；
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		“case1最后判断，即换色最后进行，防止换色后导致本应旋转的不旋转”？）
		*/
		/*if (isRed(parentNode.leftchild) && isRed(parentNode.rightchild)) flipColor(parentNode);//case1
		if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.rightchild)) parentNode.leftchild=leftRotate(parentNode.leftchild);//case3
		if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.leftchild)) parentNode=rightRotate(parentNode);//case2
		if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.leftchild)) parentNode.rightchild=rightRotate(parentNode.rightchild);//case5
		if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.rightchild)) parentNode=leftRotate(parentNode);//case4*/
        /*标准版红黑树*/
		/*
		1.如果左右子结点均为红，且左子结点的子结点或右子结点的子结点为红，则颜色反转；（红黑树性质4）
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		case1最先进行判断是因为先换色后，可以减少旋转次数。）
		*/
        if (isRed(parentNode.leftchild) && isRed(parentNode.rightchild) && (isRed(parentNode.leftchild.leftchild) || isRed(parentNode.leftchild.rightchild) || isRed(parentNode.rightchild.leftchild) || isRed(parentNode.rightchild.rightchild))) flipColor(parentNode);//case1
        if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.rightchild)) leftRotate(parentNode.leftchild);//case3
        if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.leftchild)) rightRotate(parentNode);//case2
        if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.leftchild)) rightRotate(parentNode.rightchild);//case5
        if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.rightchild)) leftRotate(parentNode);//case4
        return parentNode;
    }
    private void insertNode(RedBlackTreeNode<Type> parentNode, RedBlackTreeNode<Type> newNode) {
        if (parentNode.data.compareTo(newNode.data) == 0){
            System.out.println("insert failed");
            return;
        }
        if (parentNode.data.compareTo(newNode.data) > 0) {
            if(parentNode.leftchild==null) {
                newNode.parent = parentNode;
                parentNode.leftchild = newNode;
            }else
                insertNode(parentNode.leftchild, newNode);
        }
        else if (parentNode.data.compareTo(newNode.data) < 0) {
            if(parentNode.rightchild==null) {
                newNode.parent = parentNode;
                parentNode.rightchild = newNode;
            }else
                insertNode(parentNode.rightchild, newNode);
        }

        /*根据红黑树规则调整左右子结点*/
        /*左倾红黑树*/
		/*
		1.如果左子结点为黑，右子结点为红，则左旋；（由2-3树衍变成红黑树的左倾规则）
		2.如果左子结点为红，且左子结点的左子结点也为红，则右旋；（红黑树性质4）
		3.如果左右子结点均为红，则颜色反转*/
		/*if(!isRed(parentNode.leftchild) && isRed(parentNode.rightchild))parentNode=leftRotate(parentNode);//如果左子结点为黑，右子结点为红，则左旋
		if (isRed(parentNode.leftchild) && isRed(parentNode.leftchild.leftchild))parentNode=rightRotate(parentNode);//如果左子结点为红，且左子结点的左子结点也为红，则右旋
		if (isRed(parentNode.leftchild) && isRed(parentNode.rightchild))flipColor(parentNode);//如果左右子结点均为红，则颜色反转*/
        /*改进版红黑树（作者：习佳威）*/
		/*
		1.如果左右子结点均为红，则颜色反转；
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		“case1最后判断，即换色最后进行，防止换色后导致本应旋转的不旋转”？）
		*/
		/*if (isRed(parentNode.leftchild) && isRed(parentNode.rightchild)) flipColor(parentNode);//case1
		if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.rightchild)) parentNode.leftchild=leftRotate(parentNode.leftchild);//case3
		if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.leftchild)) parentNode=rightRotate(parentNode);//case2
		if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.leftchild)) parentNode.rightchild=rightRotate(parentNode.rightchild);//case5
		if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.rightchild)) parentNode=leftRotate(parentNode);//case4*/
        /*标准版红黑树*/
		/*
		1.如果左右子结点均为红，且左子结点的子结点或右子结点的子结点为红，则颜色反转；（红黑树性质4）
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		case1最先进行判断是因为先换色后，可以减少旋转次数。）
		*/
        if (isRed(parentNode.leftchild) && isRed(parentNode.rightchild) && (isRed(parentNode.leftchild.leftchild) || isRed(parentNode.leftchild.rightchild) || isRed(parentNode.rightchild.leftchild) || isRed(parentNode.rightchild.rightchild)))
            flipColor(parentNode);//case1
        if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.rightchild))
            leftRotate(parentNode.leftchild);//case3
        if (isRed(parentNode.leftchild) && !isRed(parentNode.rightchild) && isRed(parentNode.leftchild.leftchild))
            rightRotate(parentNode);//case2
        if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.leftchild))
            rightRotate(parentNode.rightchild);//case5
        if (isRed(parentNode.rightchild) && !isRed(parentNode.leftchild) && isRed(parentNode.rightchild.rightchild))
            leftRotate(parentNode);//case4
    }
    private RedBlackTreeNode<Type> findNode(RedBlackTreeNode<Type> parentNode, Type data) {
        if (null == parentNode) return null;
        if (parentNode.data == data) return parentNode;
        if (parentNode.data.compareTo(data) > 0)
            return findNode(parentNode.leftchild, data);
        else return findNode(parentNode.rightchild, data);
    }
    private void removeNode(RedBlackTreeNode<Type> treeNode, Type data) {
        if (null == treeNode) return;
        if (treeNode.data.compareTo(data) == 0) {
            if (treeNode.leftchild == null&&treeNode.rightchild == null){
                adjustBeforeRemove(treeNode);
                if(null!=treeNode.parent)
                    if(treeNode==treeNode.parent.leftchild)
                        treeNode.parent.leftchild = null;
                    else treeNode.parent.rightchild = null;
            } else if (treeNode.leftchild != null && treeNode.rightchild == null) {
                treeNode.data=treeNode.leftchild.data;
                adjustBeforeRemove(treeNode.leftchild);
                treeNode.leftchild=treeNode.leftchild.leftchild;
                treeNode.rightchild=treeNode.leftchild.rightchild;
            }
            else if (treeNode.leftchild == null && treeNode.rightchild != null) {
                treeNode.data=treeNode.rightchild.data;
                adjustBeforeRemove(treeNode.rightchild);
                treeNode.leftchild=treeNode.rightchild.leftchild;
                treeNode.rightchild=treeNode.rightchild.rightchild;
            }
            else if (treeNode.leftchild != null && treeNode.rightchild != null) {
                treeNode.data = findMinNode(treeNode.rightchild).data;
                treeNode.rightchild=removeMinNode(treeNode.rightchild);
            }
        }
        else if (treeNode.data.compareTo(data) > 0)
            removeNode(treeNode.leftchild, data);
        else if (treeNode.data.compareTo(data) < 0)
            removeNode(treeNode.rightchild, data);
    }
    private RedBlackTreeNode<Type> findMinNode(RedBlackTreeNode<Type> parentNode) {
        while (null != parentNode.leftchild)
            parentNode=parentNode.leftchild;
        return parentNode;
    }
    RedBlackTreeNode<Type> removeMinNode(RedBlackTreeNode<Type> parentNode) {
        if (null == parentNode.leftchild) {
            if(null == parentNode.rightchild) {
                adjustBeforeRemove(parentNode);
                return parentNode.rightchild;
            }
            else {
                parentNode.data=parentNode.rightchild.data;
                parentNode.rightchild=null;
                return parentNode;
            }
        }
        parentNode.leftchild=removeMinNode(parentNode.leftchild);
        return parentNode;
    }
    private void adjustBeforeRemove(RedBlackTreeNode<Type> treeNode){
        /*如果要删除结点的左右子结点为空，且颜色为黑，则要进行调整*/
        // 从待删结点为结点的左右子结点考虑，各分5种情况：
        // case1:待删除的结点为左结点，兄弟结点为黑且兄弟结点有且只有一个红色右子结点，则将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的子结点变黑，最后父结点左旋，调整完毕
        // case2:待删除的结点为左结点，兄弟结点为黑且兄弟结点有且只有一个红色左子结点，则将兄弟结点和兄弟结点的子结点的颜色互换，然后兄弟结点右旋，此时转成case1，执行case1的步骤，调整完毕
        // case3:待删除的结点为左结点，兄弟结点为黑且兄弟结点有两个红色的左右子结点，则执行case1相同的步骤，将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的右子结点变黑，最后父结点左旋，调整完毕
        // case4:待删除的结点为左结点，兄弟结点为黑且兄弟结点没有子结点，则将兄弟结点变红，以父结点为起点向上递归，直到遇到红色结点或根结点结束递归，并将其变黑
        // case5:待删除的结点为左结点，兄弟结点为红且兄弟结点有两个黑色的左右子结点，则将兄弟结点变黑，兄弟结点的左子结点变红，然后父结点左旋，调整完毕
        // case1:待删除的结点为右结点，兄弟结点为黑且兄弟结点有且只有一个红色左子结点，则将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的子结点变黑，最后父结点右旋，调整完毕
        // case2:待删除的结点为右结点，兄弟结点为黑且兄弟结点有且只有一个红色右子结点，则将兄弟结点和兄弟结点的子结点的颜色互换，然后兄弟结点左旋，此时转成case1，执行case1的步骤，调整完毕
        // case3:待删除的结点为右结点，兄弟结点为黑且兄弟结点有两个红色的左右子结点，则执行case1相同的步骤，将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的左子结点变黑，最后父结点右旋，调整完毕
        // case4:待删除的结点为右结点，兄弟结点为黑且兄弟结点没有子结点，则将兄弟结点变红，以父结点为起点向上递归，直到遇到红色结点或根结点结束递归，并将其变黑
        // case5:待删除的结点为右结点，兄弟结点为红且兄弟结点有两个黑色的左右子结点，则将兄弟结点变黑，兄弟结点的右子结点变红，然后父结点右旋，调整完毕
        while (treeNode!=root&&treeNode.color==Color.black) {
            if (treeNode == treeNode.parent.leftchild) {
                if (treeNode.parent.rightchild.color == Color.black) {
                    if (treeNode.parent.rightchild.leftchild == null && treeNode.parent.rightchild.rightchild != null) {
                        /*treeNode.parent.rightchild.color = treeNode.parent.color;
                        treeNode.parent.color = Color.black;*/
                        treeNode.parent.rightchild.rightchild.color = Color.black;
                        leftRotate(treeNode.parent);
                        break;
                    } else if (treeNode.parent.rightchild.leftchild != null && treeNode.parent.rightchild.rightchild == null) {
                        /*treeNode.parent.rightchild.color = Color.red;
                        treeNode.parent.rightchild.leftchild.color = Color.black;*/
                        rightRotate(treeNode.parent.rightchild);//转成case1
                        /*treeNode.parent.rightchild.color = treeNode.parent.color;
                        treeNode.parent.color = Color.black;*/
                        treeNode.parent.rightchild.rightchild.color = Color.black;
                        leftRotate(treeNode.parent);
                        break;
                    } else if (treeNode.parent.rightchild.leftchild != null && treeNode.parent.rightchild.rightchild != null) {
                        /*treeNode.parent.rightchild.color = treeNode.parent.color;
                        treeNode.parent.color = Color.black;*/
                        treeNode.parent.rightchild.rightchild.color = Color.black;
                        leftRotate(treeNode.parent);
                        break;
                    } else if (treeNode.parent.rightchild.leftchild == null && treeNode.parent.rightchild.rightchild == null) {
                        treeNode.parent.rightchild.color = Color.red;
                        treeNode = treeNode.parent;//向上递归
                    }
                }else if (treeNode.parent.rightchild.color == Color.red && treeNode.parent.rightchild.leftchild != null && treeNode.parent.rightchild.rightchild != null) {
                    treeNode.parent.rightchild.color = Color.black;
                    treeNode.parent.rightchild.leftchild.color = Color.red;
                    leftRotate(treeNode.parent);
                    break;
                }
            }
            else if (treeNode == treeNode.parent.rightchild) {
                if (treeNode.parent.leftchild.color == Color.black) {
                    if (treeNode.parent.leftchild.leftchild != null && treeNode.parent.leftchild.rightchild == null) {
                        /*treeNode.parent.leftchild.color = treeNode.parent.color;
                        treeNode.parent.color = Color.black;*/
                        treeNode.parent.leftchild.leftchild.color = Color.black;
                        rightRotate(treeNode.parent);
                        break;
                    } else if (treeNode.parent.leftchild.leftchild == null && treeNode.parent.leftchild.rightchild != null) {
                        /*treeNode.parent.leftchild.color = Color.red;
                        treeNode.parent.leftchild.rightchild.color = Color.black;*/
                        leftRotate(treeNode.parent.leftchild);
                        /*treeNode.parent.leftchild.color = treeNode.parent.color;
                        treeNode.parent.color = Color.black;*/
                        treeNode.parent.leftchild.leftchild.color = Color.black;
                        rightRotate(treeNode.parent);
                        break;
                    } else if (treeNode.parent.leftchild.leftchild != null && treeNode.parent.leftchild.rightchild != null) {
                        /*treeNode.parent.leftchild.color = treeNode.parent.color;
                        treeNode.parent.color = Color.black;*/
                        treeNode.parent.leftchild.leftchild.color = Color.black;
                        rightRotate(treeNode.parent);
                        break;
                    } else if (treeNode.parent.leftchild.leftchild == null && treeNode.parent.leftchild.rightchild == null) {
                        treeNode.parent.leftchild.color = Color.red;
                        treeNode = treeNode.parent;//向上递归
                    }
                }else if (treeNode.parent.leftchild.color == Color.red && treeNode.parent.leftchild.leftchild != null && treeNode.parent.leftchild.rightchild != null) {
                    treeNode.parent.leftchild.color = Color.black;
                    treeNode.parent.leftchild.rightchild.color = Color.red;
                    rightRotate(treeNode.parent);
                    break;
                }
            }
        }
        if(null!=treeNode)treeNode.color=Color.black;
    }
    private void preOrderTraverse(RedBlackTreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            System.out.print(treeNode.data + " ");
            preOrderTraverse(treeNode.leftchild);
            preOrderTraverse(treeNode.rightchild);
        }
    }
    private void inOrderTraverse(RedBlackTreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            inOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data + " ");
            inOrderTraverse(treeNode.rightchild);
        }
    }
    private void postOrderTraverse(RedBlackTreeNode<Type> treeNode) {
        if (null == treeNode)return;
        else
        {
            postOrderTraverse(treeNode.rightchild);
            postOrderTraverse(treeNode.leftchild);
            System.out.print(treeNode.data + " ");
        }
    }
    /*层次遍历，非递归*/
    private void levelOrderTraverse(RedBlackTreeNode<Type> root) {
        Queue<RedBlackTreeNode<Type>> queue=new LinkedList<>();//辅助队列，用于层次遍历
        if (root == null) {
            return;
        }
        queue.add(root);
        RedBlackTreeNode<Type> temp = null;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.poll();
                System.out.print(temp.data + " ");
                if (temp.leftchild != null) {
                    queue.add(temp.leftchild);
                }
                if (temp.rightchild != null) {
                    queue.add(temp.rightchild);
                }
            }
            System.out.print("\n");//换行
        }
    }
    /*将树结点以矩阵形式写入，最后打印矩阵即可形象地将树展示出来。
    因为树的结点位置与其父结点位置相关，所以递归参数时需要传递父结点的位置。*/
    private void writeArray(RedBlackTreeNode<Type> node, String[][] array, int row, int col) {
        if (root == null)return;
        //array[row][col] = node.data.toString();
        array[row][col] = node.data.toString()+"-"+node.color.toString().substring(0,1);//加上颜色
        int level = row / 2 + 1;
        if (level == m_height)return;

        /*递归左右子结点*/
        //int gap = pow(2, m_height - level - 1) * 3;//3,6,12,...
        int gap = (2 << (m_height - level - 1));//2,4,8,...
        if (node.leftchild != null) {
            array[row + 1][col - gap / 2] = "/";
            writeArray(node.leftchild, array, row + 2, col - gap);
        }
        if (node.rightchild != null) {
            array[row + 1][col + gap / 2] = "\\";
            writeArray(node.rightchild, array, row + 2, col + gap);
        }
    }

    public void insert(Type data) {
        RedBlackTreeNode<Type> newNode=new RedBlackTreeNode<>();
        newNode.data=data;
        if(null==root){
            root=newNode;
            root.color = Color.black;
            return;
        }
        insertNode(root, newNode);
        root.color = Color.black;
    }
    public RedBlackTreeNode<Type> find(Type data) { return findNode(root, data); }
    public void remove(Type data) {
        removeNode(root, data);
    }
    public RedBlackTreeNode<Type> findMin(){return findMinNode(root);}
    public void removeMin() { root=removeMinNode(root); }
    public void preOrder() {
        preOrderTraverse(root);
        System.out.print("\n");
    }
    public void inOrder() {
        inOrderTraverse(root);
        System.out.print("\n");
    }
    public void postOrder() {
        postOrderTraverse(root);
        System.out.print("\n");
    }
    public void levelOrder() { levelOrderTraverse(root); }
    public void printTree(){
        if(null==root)return;
        m_height = height(root);//树高度
        //int width = (pow(2, m_height - 1) - 1) * 6 + 1;//((2 << (m_height - 2)) - 1) * 6 + 1;//0+1,3*2+1,9*2+1,21*2+1,...,6*(pow(2,level-1)-1)+1
        int width = (int)(Math.pow(2, m_height - 1) - 1) * 4 + 1;//((2 << (m_height - 2)) - 1) * 4 + 1;//0+1,2*2+1,6*2+1,14*2+1,...,4*(pow(2,level-1)-1)+1
        //string array[2 * m_height - 1][width];
        String[][] array=new String[2 * m_height - 1][];
        for (int i = 0; i < 2 * m_height - 1; i++) {
            array[i] = new String[width];
            for (int j = 0; j < width; j++) {
                array[i][j] = " ";
            }
        }
        int a = 2 << (m_height - 2);
        //writeArray(root, array, 0, (pow(2, m_height - 1) - 1) * 3);//(pow(2, m_height - 1) - 1) * 3;
        writeArray(root, array, 0, (int) (Math.pow(2, m_height - 1) - 1) * 2);//(pow(2, m_height - 1) - 1) * 2;
        /*打印矩阵*/
        for (int i = 0; i < 2 * m_height - 1; i++) {
            for (int j = 0; j < width; j++) {
                System.out.print(array[i][j]);
            }
            System.out.print("\n");//换行
        }
    }
};

/**
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年4月7日
 *描述: 实现B树的插入、删除、查找及打印功能
 */
/*平衡树（英文名Balance Tree，简称B树），是一种多路查找树（多路搜索树或多路排序树），其中2-3树是阶数为3的B树。*/
class BalanceTreeNode<Type> {
    int count;
    int level;//结点高度，叶子结点的level为1
    Type data[];//关键字
    BalanceTreeNode<Type> child[];
    BalanceTreeNode<Type> parent;

    BalanceTreeNode() {
        parent = null;
        count = 0;
    }

    /*BalanceTreeNode(int m) {
        parent = null;
        count = 0;
        data = new Type[m];//m表示b树阶数，关键字最多存储m-1个。定义长度为m的关键字数组，多出的1个空间是为了在插入结点的关键字满时使用
        this.child = new BalanceTreeNode[m + 1];//子结点最多m个。定义长度为m+1的子结点数组，多出的1个空间是为了在插入结点的子结点数满时使用
    }*/

    BalanceTreeNode(Class<Type> typeClass,int m) {
        parent = null;
        count = 0;
        //data = (Type[]) new Object[m];//此方式创建泛型数组不可取，虽然在编译的时候不会有异常产生，但是程序运行过程中泛型数组的类型信息会被擦除，数组的类型有且仅有Object[]
        data = (Type[]) Array.newInstance(typeClass, m);//m表示b树阶数，关键字最多存储m-1个。定义长度为m的关键字数组，多出的1个空间是为了在插入结点的关键字满时使用
        this.child = new BalanceTreeNode[m + 1];//子结点最多m个。定义长度为m+1的子结点数组，多出的1个空间是为了在插入结点的子结点数满时使用
    }
}
class BalanceTree<Type extends Comparable> {
    private BalanceTreeNode<Type> root;
    private int m;
    private int min;
    private int m_size;
    private Class<Type> typeClass;

    public BalanceTree(int m) {
        root=null;m_size=0;
        this.m = m;
        this.min = (this.m - 1) / 2;
    }
    public BalanceTree(Class<Type> typeClass,int m) {
        root=null;m_size=0;
        this.m = m;
        this.min = (this.m - 1) / 2;
        this.typeClass=typeClass;
    }
    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        release(root);
    }

    private void release(BalanceTreeNode<Type> treeNode) {
        if (null != treeNode) {
            if (treeNode.level != 1)
                for (int i = 0; i <= treeNode.count; i++)
                    release(treeNode.child[i]);
            treeNode=null;
        }
    }
    private int level(BalanceTreeNode<Type> node) {
        return (null == node) ? 0 : node.level;
    }
    private void insertNode(BalanceTreeNode<Type> treeNode, Type data) {
        if (treeNode.level == 1)
        {//如果当前结点是叶子结点，插入到当前结点
            int index=0;
            for (int i = treeNode.count - 1; i >= 0; i--) {
                if (treeNode.data[i] == data) {
                    System.out.println("insert failed");
                    return;
                }
                if (treeNode.data[i].compareTo(data) > 0) {
                    treeNode.data[i + 1] = treeNode.data[i];
                    index = i;
                }
                else {
                    index = i + 1;
                    break;
                }
            }
            treeNode.data[index] = data;
            treeNode.count++;
            this.m_size++;
        }
        else
        {//如果当前结点非叶子结点，插入到当前结点的子结点中
            int i;
            for (i = 0; i < treeNode.count; i++) {
                if (treeNode.data[i] == data) {
                    System.out.println("insert failed");
                    return;
                }
                if (treeNode.data[i].compareTo(data) > 0)
                    break;
            }
            insertNode(treeNode.child[i], data);
        }

        /*分裂调整*/
        if (treeNode.count == this.m)
        {
            //BalanceTreeNode<Type> brotherNode = new BalanceTreeNode<Type>(this.m);
            BalanceTreeNode<Type> brotherNode = new BalanceTreeNode<Type>(typeClass,this.m);
            int index = 0, middle = this.m / 2;
			/*for (int i = middle + 1; i < treeNode.count; i++)
				brotherNode.data[index++] = treeNode.data[i];*/
            if (treeNode.level == 1) {
                for (int i = middle + 1; i < treeNode.count; i++)
                    brotherNode.data[index++] = treeNode.data[i];
            }
            else
            {
                for (int i = middle + 1; i < treeNode.count; i++)
                {
                    brotherNode.data[index] = treeNode.data[i];
                    brotherNode.child[index] = treeNode.child[i];
                    treeNode.child[i].parent = brotherNode;
                    index++;
                }
                brotherNode.child[index] = treeNode.child[treeNode.count];
                treeNode.child[treeNode.count].parent = brotherNode;
            }
            brotherNode.count = index;
            brotherNode.level = treeNode.level;
            treeNode.count = middle;

            if (root == treeNode) {
                //BalanceTreeNode<Type> parentNode = new BalanceTreeNode<Type>(this.m);
                BalanceTreeNode<Type> parentNode = new BalanceTreeNode<Type>(typeClass,this.m);
                parentNode.data[0] = treeNode.data[middle];
                parentNode.child[0] = treeNode;
                parentNode.child[1] = brotherNode;
                treeNode.parent = parentNode;
                brotherNode.parent = parentNode;
                parentNode.count++;
                parentNode.level = treeNode.level + 1;
                this.root = parentNode;
            }
            else
            {
                for (int i = treeNode.parent.count; i >= 0; i--) {
                    if (treeNode.parent.child[i] != treeNode) {
                        treeNode.parent.data[i] = treeNode.parent.data[i - 1];
                        treeNode.parent.child[i + 1] = treeNode.parent.child[i];
                        index = i;
                    }
                    else
                    {
                        index = i + 1;
                        break;
                    }
                }
                treeNode.parent.data[index-1] = treeNode.data[middle];
                treeNode.parent.child[index] = brotherNode;
                brotherNode.parent = treeNode.parent;
                treeNode.parent.count++;
            }
        }
    }
    private BalanceTreeNode<Type> findNode(BalanceTreeNode<Type> treeNode, Type data) {
        int i;
        for (i = 0; i < treeNode.count; i++) {
            if (treeNode.data[i] == data) {
                return treeNode;
            }
            else if (treeNode.data[i].compareTo(data) > 0) {
                break;
            }
        }
        if (treeNode.level == 1)return null;
        else return findNode(treeNode.child[i], data);
    }
    private void removeNode(BalanceTreeNode<Type> treeNode, Type data) {
        if (treeNode.level == 1)
        {
            /*如果当前结点是叶子结点，考虑当前结点关键字数是否大于下限min
			1.如果当前结点关键字数大于下限min，则直接删除
			2.否则，考虑其左右兄弟结点的关键字数是否大于下限min。如果其左右兄弟结点的关键字数不全为下限，则从其中关键字数大于下限的兄弟结点借一个元素；如果其左右兄弟结点的关键字数刚好都为下限，则与其中一个兄弟结点合并，并向上递归*/
            int i;
            for (i = 0; i < treeNode.count; i++) {
                if (treeNode.data[i] == data)
                    break;
            }
            if (i == treeNode.count) System.out.println("remove failed");
            else
            {
                if (treeNode.count > min) {
                    for (int j = i; j < treeNode.count; j++) {
                        treeNode.data[j] = treeNode.data[j + 1];
                    }
                    treeNode.count--;
                    this.m_size--;
                    return;
                }
                else
                {
                    int index;
                    for (index = 0; index <= treeNode.parent.count; index++) {
                        if (treeNode.parent.child[index] == treeNode)
                            break;
                    }
                    if (index > 0 && treeNode.parent.child[index - 1].count > min) {
                        for (int j = 0; j < i; j++)
                            treeNode.data[j + 1] = treeNode.data[j];
                        treeNode.data[0] = treeNode.parent.data[index - 1];
                        treeNode.parent.data[index - 1] = treeNode.parent.child[index - 1].data[treeNode.parent.child[index - 1].count - 1];
                        treeNode.parent.child[index - 1].count--;
                        return;
                    }
                    if (index < treeNode.parent.count && treeNode.parent.child[index + 1].count > min) {
                        for (int j = i; j < treeNode.count; j++)
                            treeNode.data[j] = treeNode.data[j + 1];
                        treeNode.data[treeNode.count - 1] = treeNode.parent.data[index];
                        treeNode.parent.data[index] = treeNode.parent.child[index + 1].data[0];
                        for (int j = 0; j < treeNode.parent.child[index + 1].count; j++)
                            treeNode.parent.child[index + 1].data[j] = treeNode.parent.child[index + 1].data[j + 1];
                        treeNode.parent.child[index + 1].count--;
                        return;
                    }
                    //如果左右兄弟结点关键字数都刚好为下限，则将值从当前结点中删除并随机选择一个兄弟结点合并
                    for (int j = i; j < treeNode.count; j++)
                        treeNode.data[j] = treeNode.data[j + 1];
                    treeNode.count--;
                    if (index < treeNode.parent.count)
                        merge(treeNode, index, 1);
                    else
                        merge(treeNode, index, -1);
                }
            }
        }
        else
        {
            /*如果当前结点非叶子结点，则从左右子结点中找到后继值（左子结点的最右键值或右子结点的最左键值），然后向下递归删除*/
            int i;
            for (i = 0; i < treeNode.count; i++) {
                if (treeNode.data[i] == data) {
                    //如果左子结点的键值数大于下限，则将左子结点的最右键值作为后继结点；否则将右子结点的最左键值作为后继结点
                    if (treeNode.child[i].count > min) {
                        treeNode.data[i] = treeNode.child[i].data[treeNode.child[i].count - 1];
                        removeNode(treeNode.child[i], treeNode.child[i].data[treeNode.child[i].count - 1]);
                        return;
                    }
                    else {
                        treeNode.data[i] = treeNode.child[i + 1].data[0];
                        removeNode(treeNode.child[i + 1], treeNode.child[i + 1].data[0]);
                        return;
                    }
                }
                if (treeNode.data[i].compareTo(data) > 0)
                    break;
            }
            removeNode(treeNode.child[i], data);
        }
    }
    /*合并兄弟结点，参数说明：
	参数treeNode表示当前要合并的结点，
	参数index表示treeNode在父结点中的位置，
	参数leftOrRight表示另外一个要合并的结点是treeNode的左兄弟结点还是treeNode的右兄弟结点，leftOrRight=-1表示左兄弟结点，leftOrRight=1表示右兄弟结点*/
    private void merge(BalanceTreeNode<Type> treeNode, int index, int leftOrRight) {
        if (treeNode.level == 1) {
            if (leftOrRight == -1) {
                for (int i = 0; i < treeNode.count; i++) {
                    treeNode.parent.child[index + leftOrRight].data[i + treeNode.parent.child[index + leftOrRight].count + 1] = treeNode.data[i];
                }
                treeNode.parent.child[index + leftOrRight].data[treeNode.parent.child[index + leftOrRight].count] = treeNode.parent.data[index - 1];
                treeNode.parent.child[index + leftOrRight].count = treeNode.count + treeNode.parent.child[index + leftOrRight].count + 1;
                //release(treeNode);
                for (int i = index - 1; i < treeNode.parent.count - 1; i++) {
                    treeNode.parent.data[i] = treeNode.parent.data[i + 1];
                    treeNode.parent.child[i + 1] = treeNode.parent.child[i + 2];
                }
            }
            else
            {
                for (int i = 0; i < treeNode.parent.child[index + leftOrRight].count; i++) {
                    treeNode.data[i + treeNode.count + 1] = treeNode.parent.child[index + leftOrRight].data[i];
                }
                treeNode.data[treeNode.count] = treeNode.parent.data[index];
                treeNode.count = treeNode.count + treeNode.parent.child[index + leftOrRight].count + 1;
                //release(treeNode.parent.child[index + leftOrRight]);
                for (int i = index; i < treeNode.parent.count - 1; i++) {
                    treeNode.parent.data[i] = treeNode.parent.data[i + 1];
                    treeNode.parent.child[i + 1] = treeNode.parent.child[i + 2];
                }
            }
            treeNode.parent.count--;
        }
        else
        {
            if (leftOrRight == -1) {
                for (int i = 0; i < treeNode.count; i++) {
                    treeNode.parent.child[index + leftOrRight].data[i + treeNode.parent.child[index + leftOrRight].count + 1] = treeNode.data[i];
                    treeNode.parent.child[index + leftOrRight].child[i + treeNode.parent.child[index + leftOrRight].count + 1] = treeNode.child[i];
                }
                treeNode.parent.child[index + leftOrRight].data[treeNode.parent.child[index + leftOrRight].count] = treeNode.parent.data[index - 1];
                treeNode.parent.child[index + leftOrRight].count = treeNode.count + treeNode.parent.child[index + leftOrRight].count + 1;
                //release(treeNode);
                for (int i = index - 1; i < treeNode.parent.count - 1; i++) {
                    treeNode.parent.data[i] = treeNode.parent.data[i + 1];
                    treeNode.parent.child[i + 1] = treeNode.parent.child[i + 2];
                }
            }
            else
            {
                for (int i = 0; i < treeNode.parent.child[index + leftOrRight].count; i++) {
                    treeNode.data[i + treeNode.count + 1] = treeNode.parent.child[index + leftOrRight].data[i];
                    treeNode.child[i + treeNode.count + 1] = treeNode.parent.child[index + leftOrRight].child[i];
                }
                treeNode.child[treeNode.count + treeNode.parent.child[index + leftOrRight].count + 1] = treeNode.parent.child[index + leftOrRight].child[treeNode.parent.child[index + leftOrRight].count];
                treeNode.data[treeNode.count] = treeNode.parent.data[index];
                treeNode.count = treeNode.count + treeNode.parent.child[index + leftOrRight].count + 1;
                //release(treeNode.parent.child[index + leftOrRight]);
                for (int i = index; i < treeNode.parent.count - 1; i++) {
                    treeNode.parent.data[i] = treeNode.parent.data[i + 1];
                    treeNode.parent.child[i + 1] = treeNode.parent.child[i + 2];
                }
            }
            treeNode.parent.count--;
        }


        /*如果treeNode的父结点为根结点且合并后父结点关键字为0，则将根结点指向treeNode父结点的第一个子结点*/
        if (root == treeNode.parent) {
            if (treeNode.parent.count == 0)
                root = treeNode.parent.child[0];
            return;
        }
        else {
            /*如果合并后父结点关键字数满足下限要求，则结束删除过程*/
            if (treeNode.parent.count >= min)
                return;

			/*如果合并后父结点关键字数不满足下限要求，则考虑其左右兄弟结点的关键字数
			1.如果其左右兄弟结点的关键字数不全为下限，则向其中大于下限的一个兄弟结点借一个关键字，同时兄弟结点的对应子结点也并入过来
			2.如果其左右兄弟结点的关键字数刚好都为下限，则向上递归合并*/
            for (index = 0; index <= treeNode.parent.parent.count; index++) {
                if (treeNode.parent.parent.child[index] == treeNode.parent)
                    break;
            }
            if (index > 0 && treeNode.parent.parent.child[index - 1].count > min) {
                for (int i = 0; i < index; i++)
                    treeNode.parent.data[i + 1] = treeNode.parent.data[i];
                treeNode.parent.data[0] = treeNode.parent.parent.data[index - 1];
                treeNode.parent.parent.data[index - 1] = treeNode.parent.parent.child[index - 1].data[treeNode.parent.parent.child[index - 1].count - 1];
                //并入左兄弟结点的最右子结点
                for (int i = treeNode.parent.count; i >= 0; i--)
                    treeNode.parent.child[i + 1] = treeNode.parent.child[i];
                treeNode.parent.child[0] = treeNode.parent.parent.child[index - 1].child[treeNode.parent.parent.child[index - 1].count];
                treeNode.parent.count++;
                treeNode.parent.parent.child[index - 1].count--;
                return;
            }
            if (index < treeNode.parent.parent.count && treeNode.parent.parent.child[index + 1].count > min) {
                treeNode.parent.data[treeNode.parent.count] = treeNode.parent.parent.data[index];
                treeNode.parent.parent.data[index] = treeNode.parent.parent.child[index + 1].data[0];
                for (int i = 0; i < treeNode.parent.parent.child[index + 1].count; i++)
                    treeNode.parent.parent.child[index + 1].data[i] = treeNode.parent.parent.child[index + 1].data[i + 1];
                //并入右兄弟结点的最左子结点
                treeNode.parent.count++;
                treeNode.parent.child[treeNode.parent.count] = treeNode.parent.parent.child[index + 1].child[0];
                treeNode.parent.parent.child[index + 1].count--;
                for (int i = 0; i <= treeNode.parent.parent.child[index + 1].count; i++)
                    treeNode.parent.parent.child[index + 1].child[i] = treeNode.parent.parent.child[index + 1].child[i + 1];
                return;
            }
            if (index < treeNode.parent.parent.count)
                merge(treeNode.parent, index, 1);
            else
                merge(treeNode.parent, index, -1);
        }
    }
    /*层次遍历，非递归*/
    private void levelOrderTraverse(BalanceTreeNode<Type> root) {
        Queue<BalanceTreeNode<Type>> queue=new LinkedList<>();//辅助队列，用于层次遍历
        if (root == null) {
            return;
        }
        queue.add(root);
        BalanceTreeNode<Type> temp = null;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                temp = queue.poll();
                System.out.print("{");
                for (int j = 0; j < temp.count-1; j++) {
                    System.out.print(temp.data[j]+" ");
                }
                System.out.print(temp.data[temp.count - 1] + "}");
                if (temp.level != 1) {
                    for (int j = 0; j <= temp.count; j++) {
                        queue.add(temp.child[j]);
                    }
                }
            }
            System.out.print("\n");//换行
        }
    }

    public void insert(Type data) {
        if (null == root) {
            //this.root = new BalanceTreeNode<Type>(this.m);
            this.root = new BalanceTreeNode<Type>(typeClass,this.m);
            this.root.data[0] = data;
            this.root.count++;
            this.root.level = 1;
            this.m_size++;
            return;
        }
        insertNode(root, data);
    }
    public BalanceTreeNode<Type> find(Type data) { return findNode(root, data); }
    public void remove(Type data) { removeNode(root, data); }
    public void levelOrder() { levelOrderTraverse(root); }
};
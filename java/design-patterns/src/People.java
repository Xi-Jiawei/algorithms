import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/*静态代码块 -> 动态代码块 ->构造函数*/
class A{
    static {System.out.println("static block a");}
    {System.out.println("dynamic block a");}
    A() { System.out.println("constructor a"); }
}
/*静态代码块 -> 动态代码块 ->构造函数
* 在不涉及继承的情况下：
* 1.静态代码块和静态成员变量在加载代码时执行，只执行一次，按照它们出现的顺序先后执行
* 2.动态代码块在每次实例化对象时执行，在构造函数之前执行，多个动态代码块按照它们出现的顺序先后执行
* 在涉及继承的情况下：
* 1.执行父类的静态代码块和静态成员变量定义，执行子类的静态代码块和静态成员变量定义
* 2.执行父类的动态代码块，执行父类的构造函数
* 3.执行子类的动态代码块，执行子类的构造函数
* 4.如果父类构造函数中用到的函数被子类重写，那么在构造子类对象时调用子类重写的方法*/
class B{
    public static int k = 1000;
    public static B b1 = new B("B1");
    public static B b2 = new B("B2");
    public static int i = print("i");
    public static int n = 1000000;
    public int j = print("j");

    static {
        print("static block b");
    }
    {
        print("dynamic block b");
    }
    public B() { System.out.println("constructor b"); }
    public B(String str) {
        System.out.println((++k) + ":" + str + "    i=" + i + "     n=" + n);
        ++i;
        ++n;
    }
    public static int print(String str) {
        System.out.println((++k) + ":" + str + "    i=" + i + "     n=" + n);
        ++n;
        return ++i;
    }

    public static void main(String args[]) {
        B t = new B("main");
    }
}

class X implements Cloneable{
    public int key;
    public int value;

    public X() { System.out.println("constructor x"); }
    public X(int key,int value) {
        this.key=key;
        this.value=value;
        System.out.println("constructor x");
    }
    public X(X x) {
        this.key=x.key;
        this.value=x.value;
        System.out.println("constructor x");
    }

    void func(){
        this.key=10;
        this.value=100;
        System.out.println("父类方法");
    }

    static void print(){System.out.println("父类静态方法");}

    public X clone(){
        X x=null;
        try{
            return x=(X)super.clone();
        } catch (CloneNotSupportedException e){
            e.printStackTrace();
        }
        return x;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        System.out.println("destructor x");
    }
}
/*构造与析构*/
class Y {
    public X xs[]=new X[3];

    public Y() { System.out.println("constructor y"); }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        System.out.println("destructor y");
    }
}
/*继承*/
class Z extends X{
    private int key;
    private int value;

    public Z() {
        super(2,3);
        System.out.println("constructor z");
        System.out.println("父类key、value: "+super.key+" "+super.value);//访问父类变量
    }

    static void print(){System.out.println("子类静态方法");}

    void func() {
        super.func();//访问父类方法
        System.out.println("子类方法");
        this.key=1000;
        this.value=10000;
        System.out.println("父类key、value: "+super.key+" "+super.value);//访问父类变量
        System.out.println("子类key、value: "+this.key+" "+this.value);
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        System.out.println("destructor y");
    }
}

abstract class People implements Cloneable{
    public String name;
    public String label;

    //工厂模式：父类统一接口，子类多种实现
    abstract void setLabel();

    //观察者模式：通知/监听
    abstract void notify(String message);
    abstract void listen(String message);

    //原型模式：复制。
    //public People clone() throws CloneNotSupportedException{ return (People)super.clone(); }
    public People clone(){
        People people=null;
        try{
            return people=(People)super.clone();
        } catch (CloneNotSupportedException e){
            e.printStackTrace();
        }
        return people;
    }

    String getLabel() { return this.label; }
}

class Student extends People {
    private List<People> listeners=new ArrayList<>();

    public Student(String name) {
        this.name = name;
    }

    public void setLabel() {
        this.label = "student";
    }

    public void registerListenner(People listener) { listeners.add(listener); }
    public void unregisterListenner(People listener) {
        Iterator<People> itr=listeners.iterator();
        while (itr.hasNext())
            if (itr.next() == listener)
                itr.remove();
    }
    public void notify(String message) {
        Iterator<People> itr=listeners.iterator();
        while (itr.hasNext())
            itr.next().listen(message);
    };
    public void listen(String message) { System.out.println(this.name+ ", " +message); }
};

class Teacher extends  People {
    private List<People> listeners=new ArrayList<>();

    public Teacher(String name) { this.name = name; }

    public void setLabel() {
        this.label = "teacher";
    }

    public void registerListenner(People listener) { listeners.add(listener); }
    public void unregisterListenner(People listener) {
        Iterator<People> itr=listeners.iterator();
        while (itr.hasNext())
            if (itr.next() == listener)
                itr.remove();
    }
    public void notify(String message) {
        Iterator<People> itr=listeners.iterator();
        while (itr.hasNext())
            itr.next().listen(message);
    };
    public void listen(String message) { System.out.println(this.name+ ", " +message); }
};

class UnderGraduate extends People {
    private List<People> listeners=new ArrayList<>();

    public UnderGraduate(People people) {
        this.name = people.name;
        this.label = people.label;
    }

    void setLabel() {
        this.label = this.label+", undergraduate";
    }

    public void registerListenner(People listener) { listeners.add(listener); }
    public void unregisterListenner(People listener) {
        Iterator<People> itr=listeners.iterator();
        while (itr.hasNext())
            if (itr.next() == listener)
                itr.remove();
    }
    public void notify(String message) {
        Iterator<People> itr=listeners.iterator();
        while (itr.hasNext())
            itr.next().listen(message);
    };
    public void listen(String message) { System.out.println(this.name+ ", " +message); }
}

/*单例模式*/
//方式一：
/*class Tom {
    private static Tom m_instance;
    private static String label;

    public Tom() { System.out.println("constructor tom"); }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        System.out.println("destructor tom");
    }

    static Tom instance() {
        if (m_instance == null) m_instance = new Tom();//new创建的对象存放在堆区，需手动释放，无法自动析构
        return m_instance;
    }
}*/
//方式二（推荐）：
class Tom {
    private static Tom m_instance = new Tom();//new创建的对象存放在堆区，需手动释放，无法自动析构
    private static int age;
    public static String label;

    public Tom() { System.out.println("constructor tom"); }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        System.out.println("destructor tom");
    }

    static Tom instance() {
        return m_instance;
    }
}

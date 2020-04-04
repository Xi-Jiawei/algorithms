public class Test {
    public static void main(String[] args) {
        /*静态代码块 -> 动态代码块 ->构造函数*/
        /*A a=new A();*/

        /*构造与析构*/
        /*X x=new X(2,3);
        x=null;
        System.gc();//new创建的对象存放在堆区，需手动释放，无法自动析构*/
        /*X x=new X(2,3);
        X x1=new X(x);
        X x2=x.clone();
        X xs[]=new X[3];
        xs[0] = x;
        xs[1] = x1;
        xs[2] = x2;
        Y y=new Y();
        y.xs=xs;
        x=null;
        x1=null;
        x2=null;
        //xs=null;//无效
        y=null;
        System.gc();*/

        /*继承*/
        /*X z=new Z();
        z.print();//父类静态方法
        z.func();*/

        /*多态*/
        /*People people;
        people=new Student("Bob");
        people.setLabel();
        System.out.println(people.name+" "+people.getLabel());
        people=new Teacher("Einstein");
        people.setLabel();
        System.out.println(people.name+" "+people.getLabel());*/

        /*单例模式*/
        /*Tom tom1=Tom.instance();
        Tom tom2=Tom.instance();
        System.out.println(tom1==tom2);*/

        /*工厂模式*/
        /*People people;
        people = new Student("Bob");
        people.setLabel();
        System.out.println(people.name+" "+people.getLabel());
        people = new Teacher("Einstein");
        people.setLabel();
        System.out.println(people.name+" "+people.getLabel());*/

        /*原型模式*/
        /*People people=new Student("Bob");
        people.setLabel();
        People people2=people.clone();
        people2.name="Tom";
        People people3=new Student("Sandy");
        System.out.println(people.name+" "+people.getLabel());
        System.out.println(people2.name+" "+people2.getLabel());
        System.out.println(people3.name+" "+people3.getLabel());*/

        /*装饰模式*/
        /*People people=new Student("Bob");
        people.setLabel();
        people=new UnderGraduate(people);
        people.setLabel();
        System.out.println(people.name+" "+people.getLabel());*/

        /*观察者模式*/
        /*Student student1 = new Student("Bob");
        Student student2 = new Student("Jerry");
        Teacher teacher = new Teacher("Einstein");
        teacher.registerListenner(student1);
        teacher.registerListenner(student2);
        teacher.notify("hand in your homework tomorrow, pelease!");*/
    }
}

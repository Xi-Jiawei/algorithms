import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        Test test=new Test();
        //test.findNumber();
        //test.circling();
        //test.sumOfConsecutiveNumber();
        //test.bigNumber3();
    }

    /*(BJTU)查找n*n方阵中的数字
    * n*n的数字矩阵上下、左右均递增，查找数字k
    * */
    private void findNumber(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt(),n,j,row,column,q,a,value[][]=new int[10000][10000];
        //System.out.println("T："+T);
        for (int i = 0; i < T; i++){
            n = scanner.nextInt();
            for (row = 0; row < n; row++){
                for (column=0;column<n;column++)
                    value[row][column]=scanner.nextInt();
            }
            q=scanner.nextInt();
            for (j = 0; j < q; j++)
            {
                a=scanner.nextInt();
                for(row=0;row<n;row++)
                    for (column=n-1-row;column<n;column++)
                    {
                        if(value[row][column]==a){
                            System.out.println("row["+a+"]："+row);
                            System.out.println("column["+a+"]："+column);
                        }else System.out.println(-1);
                    }
            }
        }
    }

    /*(BJTU)有趣的无限循环小数
    * 判断a/b是否为有限小数，若为无限循环小数，求其循环节且循环节长度不超过9
    * 存在Bug，待修改*/
    private void infiniteDecimal(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        int T=scanner.nextInt(),a,b,tempa,tempb,temp,a_b=0,numerator,denominator,num,quotient[]=new int[10],i,j,r,remainder,count;
        //System.out.println("T："+T);
        for(int k=0;k<T;k++) {
            a=scanner.nextInt();
            b=scanner.nextInt();
            tempa=a;
            tempb=b;
            while (tempa!=0){
                temp=tempb%tempa;
                tempb=tempa;
                tempa=temp;
            }
            a_b=tempb;
            numerator=a/a_b;
            denominator=b/a_b;
            //System.out.print("numerator: "+numerator);
            //System.out.print("denominator: "+denominator);
            while (denominator % 2 == 0)
                denominator /= 2;
            while (denominator % 5 == 0)
                denominator /= 5;
            if(denominator == 1)System.out.println("Case #"+(k+1)+": heiheihei");
            else {
                i = 0;
                count=0;
                num=numerator;
                while (num / denominator<1){
                    num=num *10;
                    count++;
                }
                //System.out.print("count: "+count);
                quotient[i] = num / denominator;//循环节第一个数字
                //System.out.print("quotient["+i+"]: "+quotient[i]);
                remainder=num%denominator;//第一次得余数
                while(remainder!=numerator)
                {
                    //System.out.println("remainder: "+remainder);
                    i++;
                    remainder=remainder*10;
                    quotient[i]=remainder/denominator;
                    //System.out.println("quotient["+i+"]: "+quotient[i]);
                    remainder=remainder%denominator;
                    if(i==9)break;
                }
                //System.out.print("i: "+i);
                System.out.print("Case #"+(k+1)+": 0.");
                for(j=0;j<count-1;j++)System.out.print(0);
                for(j=0;j<i;j++)System.out.print(quotient[j]);
                System.out.println(quotient[i]);
            }
        }
    }

    /*(BJTU)
    * 如果存在全班至少p%的人同时选3门相同的课，则输出“yes”，否则输出“no”*/
    /*未完成*/
    private void coursesSelected(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt(), n, p,  i, j, l, row, column, a[][], student_count[][][] = new int[60][59][58], c[], d[], e[], count[] = new int[61],
                count_num[] = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
                max, max_num, min_num, sum;
        float p_n;
        boolean flag;
        //System.out.println("T："+T);
        for (int k = 0; k < T; k++) {
            n = scanner.nextInt();
            p = scanner.nextInt();
            p_n = (float)n * p / 100;
            a = new int[n][5];
            for (i = 0; i < n; i++) {
                for (j = 0; j < 5; j++) {
                    a[i][j] = scanner.nextInt();
                    count[a[i][j]]++;//课程号被选次数统计
                }
            }
            /*课程号出现频率排序*/
            for (i = 1; i < 60; i++)
                for (j = 60; j > i; j--) {
                    if (count[j] > count[j - 1]) {
                        max = count[j - 1];
                        count[j - 1] = count[j];
                        count[j] = max;
                        max_num = count_num[j];//课程序号调换
                        count_num[j] = count_num[j - 1];
                        count_num[j - 1] = max_num;
                    }
                }
            min_num = 60;
            for (l = 1; l <= 60; l++) {
                System.out.println("count_num[" + l + "]:" + count_num[l]);
                System.out.println("count[" + l + "]:" + count[l]);
                if (count[l] < p_n) {
                    min_num = l - 1;
                    break;
                }
            }
            System.out.println("p_n:" + p_n);
            System.out.println("min_num:" + min_num);
            /*将count_num组合轮询*/
            if(min_num>=3){
                for (l = 1; l <= min_num - 2; l++) {
                    for (i = l + 1; i <= min_num - 1 && i != l; i++) {
                        for (j = i + 1; j <= min_num && j != i && j != l; j++) {
                            System.out.println("count_num[" + l + "][" + i + "][" + j + "]:" + count_num[l] + " " + count_num[i] + " " + count_num[j]);
                            for (row = 0; row < n; row++) {
                                flag = false;
                                sum = 0;
                                for (column = 0; column < 5; column++) {
                                    if (a[row][column] == count_num[l]) {
                                        flag = true;
                                        sum++;
                                        if (sum == 3) break;
                                        else continue;
                                    } else flag = false;
                                    if (a[row][column] == count_num[i]) {
                                        flag = true;
                                        sum++;
                                        if (sum == 3) break;
                                        else continue;
                                    } else flag = false;
                                    if (a[row][column] == count_num[j]) {
                                        flag = true;
                                        sum++;
                                        if (sum == 3) break;
                                        else continue;
                                    } else flag = false;
                                }
                                if (flag) student_count[l][i][j]++;//组合l,i,j的同时被选人数
                            }
                        }
                    }
                }
                flag = false;
                for (l = 1; l <= min_num - 2; l++) {
                    for (i = l + 1; i <= min_num - 1 && i != l; i++) {
                        for (j = i + 1; j <= min_num && j != i && j != l; j++) {
                            //System.out.println("student_count[" + l + "][" + i + "][" + j + "]:" + student_count[l][i][j]);
                            if (student_count[l][i][j] >= p_n) {
                                System.out.println("yes");
                                flag = true;
                                break;
                            }
                        }
                        if (flag) break;
                    }
                    if (flag) break;
                }
                if (!flag) System.out.println("no");
            }else System.out.println("no");
        }
    }

    /*(BJTU)Umi's Problem*/
    private void problemOfUmi(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt(), n, i, firstindexofopenparen, lastindexofcloseparen, count_paren, count, result;
        //System.out.println("T："+T);
        boolean flag, beginflag, endflag;
        String s;
        for (int k = 0; k < T; k++) {
            n = scanner.nextInt();
            s = scanner.next();
            firstindexofopenparen = s.indexOf("(");
            lastindexofcloseparen = s.lastIndexOf(")");
            if (firstindexofopenparen == -1) System.out.println("Case #" + (k + 1) + ": " + 0);
            else {
                count_paren = 0;
                count = 0;
                result = 0;
                beginflag = false;//右括号开始标志
                endflag = false;//右括号结束标志
                flag = true;//前一时刻为左还是右括号的标记
                for (i = firstindexofopenparen; i <= lastindexofcloseparen; i++) {
                    if (s.charAt(i) == '(') {
                        if (flag) {
                            beginflag = false;
                            endflag = false;
                        } else {
                            beginflag = false;
                            endflag = true;
                        }
                        flag = true;
                        count_paren++;
                    }
                    if (s.charAt(i) == ')') {
                        if (!flag) {
                            beginflag = true;
                            endflag = true;
                        } else {
                            beginflag = true;
                            endflag = false;
                        }
                        flag = false;
                        count_paren--;
                    }
                    //System.out.println("i：" + i);
                    //System.out.println("beginflag：" + beginflag);
                    //System.out.println("endflag：" + endflag);
                    //System.out.println("count_paren：" + count_paren);
                    if (beginflag && !endflag && count_paren >= 0) {
                        count++;
                    }
                    if ((!beginflag && endflag) || count_paren == 0) {
                        result += (count + 1) * count / 2;
                        count_paren = 1;
                        count = 0;
                        //System.out.println("result：" + result);
                    }
                    //System.out.println("count：" + count);
                }
                System.out.println("Case #" + (k + 1) + ": " + result);
            }
        }
    }

    /*(BJTU)A Simple Problem
     * 求 0~n 中有多少个整数 k 满足 (2 * k) XOR (3 * k) == k, 其中 XOR 为异或操作
     * 注：未考虑相等的整数n
     * */
    private void findK(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt(),j,n[]=new int[T],count,temp,n_n[]=new int[T];
        //System.out.println("T："+T);
        count=0;
        for(int i=0;i<T;i++){
            n[i]=scanner.nextInt();
            n_n[i]=i;
            //System.out.println("n[" + i + "]: " +n[i]);
        }
        for(int i=0;i<T-1;i++){
            for(j=0;j<T-1-i;j++){
                if(n[j]>n[j+1]){
                    temp=n[j];
                    n[j]=n[j+1];
                    n[j+1]=temp;
                    temp=n_n[j];
                    n_n[j]=n_n[j+1];
                    n_n[j+1]=temp;
                }
            }
        }
        /*for(int i=0;i<T;i++){
            System.out.println("n[" + i + "]: " +n[i]);
            System.out.println("n_n[" + i + "]: " +n_n[i]);
        }*/
        j=0;
        for(int i=0;;i++){
            if (((i * 2) ^ (i * 3)) == i) {
                count++;
            }
            if(i==n[j]){
                System.out.println("Case #" + (n_n[j] + 1) + ": " + count);
                j++;
                if(j==T)break;
            }
        }
    }

    /*(BJTU)绕圆圈
    * 题面描述：
    * 小明报名参加了趣味运动会，运动会游戏规则如下：在一个环形跑道上，等距离放置着 N 个小球，小球按照顺时针方向从起点开始依次编号为 1 到 N ，在最短时间内取走放在跑道上尽可能多小球的选手获胜。举办方要求每个选手只能按照顺时针方向，跳过 M-1 个号码取后走下一个小球。如当 N=5 、 M=3 时，小明能够取走所有的小球，取走的顺序依次为 1->4->2->5->3 。当 N=6 、 M=2 时，小明只能取走 3 个小球 1->3->5 。小明想知道在一场比赛中他最多能取走多少小球，当然，小明是知道怎么做的，但是他忙着补作业，所以这个简单的问题就交给你了。
    * 输入数据：
    * 输入数据的第一行为一个整数 T ，表示有 T 组测试样例。每组样例为单独的一行，包括两个整数 N 和 M 。
    * 输出数据：
    * 对每一组输入数据，输出一行结果 ”Case #id: M” ，表示第 id 组数据的结果是 M ， id 从 1 开始。
    * 样例输入：
    * 3
    * 5 3
    * 6 2
    * 10 6
    * 样例输出：
    * Case #1: 5
    * Case #2: 3
    * Case #3: 5
    * */
    private void circling(){
        System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        int T=Integer.parseInt(scanner.nextLine());
        System.out.println("T："+T);
        int add;
        int remainder;
        int count;
        int j;
        int[] num=new int[2];
        for(int i=1;i<=T;i++){
            System.out.println("请输入第"+i+"组数字N、M：");
            scanner=new Scanner(System.in);
            //System.out.println("mark");
            j=0;
            while(scanner.hasNext()){
                num[j] = scanner.nextInt();//N存入num[0]，M存入num[1]
                //System.out.println("num["+j+"]："+num[j]);
                j++;
                if(j>=2)break;
            }
            System.out.println("N："+num[0]+"、M："+num[1]);

            add=1;
            count=0;
            do{
                count++;
                remainder=(add+=num[1])%num[0];//取余，当余数为开始值1时，表示此后的操作只是在作循环
            }while (remainder!=1);
            System.out.println("Case #"+i+"："+count);
        }
    }
    private void circling2(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        int p=1;
        int remainder=0;
        int count=0;
        int N=0,M=0;
        int[] result=new int[T+1];
        //System.out.println(scanner.hasNext());
        for(int i=0;i<T;i++){
            while(scanner.hasNext()){
                //num[j] = scanner.nextInt();//N存入num[0]，M存入num[1]
                //System.out.println(num[j]);
                //j++;
                //System.out.println(scanner.next());
                //System.out.println(scanner.next());
                N=scanner.nextInt();
                M=scanner.nextInt();
                break;
            }
            //System.out.println(N+M);

            if(N!=0&&M!=0){
                //System.out.println("mark");
                p=1;
                count=0;
                do{
                    count++;
                    remainder=(p+=M)%N;//取余，当余数为开始值1时，表示此后的操作只是在作循环
                }while (remainder!=1);
                //System.out.println("Case #"+i+"："+count);
                //System.out.println("N："+num[0]+"、M："+num[1]);
            }
            else{
                //System.out.println("输入异常：N、M不能为零！");
                count=1;
            }
            result[i]=count;
        }

        for(int r=0;r<T;r++){
            int id=r+1;
            System.out.println("Case #"+id+": "+result[r]);
        }
    }
    private void circling3(){
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        int p=1;
        int remainder=0;
        int count=0;
        int N=0,M=0;
        int j=2;
        boolean MnotN=true;//表明N与M存在最大公约数
        int[] result=new int[T];
        for(int i=0;i<T;i++){
            N=scanner.nextInt();
            //System.out.println("N："+N);
            count=0;
            if(N>2&&N%2!=0){
                count++;
                for(M=4;M<N;M+=2){
                    for(j=2;j<=M;j++){
                        //System.out.println(M);
                        if((N%j==0)&&(M%j==0)){
                            MnotN=false;break;
                        }else{MnotN=true;}
                    }
                    if(MnotN){
                        count++;
                        //System.out.println(M);
                    }
                }
            }
            //else{for(M=3;M<N;M++){
            //for(j=2;j<=M;j++){
            //if((N%j==0)&&(M%j==0)){
            //MnotN=false;break;
            //}else{MnotN=true;}
            //}
            //if(MnotN){
            //count++;MnotN=true;
            //System.out.println(M);
            //}
            //}
            result[i]=count;
        }

        for(int r=0;r<T;r++){
            int id=r+1;
            System.out.println("Case #"+id+": "+result[r]);
        }
    }

    /*(BJTU)连续数的和
     *对于一个给定的正整数 n ，请你找出一共有多少种方式使 n 表示为若干个连续正整数的和，要求至少包括两个正整数。如 n=15 时，可以有 3 种方式：（ 1+2+3+4+5 ），（ 4+5+6 ），（ 7+8 ）。输入数据第一行为一个正整数 T ，表示测试数据的组数。 随后的 T 行中，每行包括一组测试数据，为一个整数 n（1≤T≤1000,n≤10^9）。对每一组输入数据，输出一行结果 ”Case #id: M” ，表示第 id 组数据的结果是 M ， id 从 1 开始。
     * */
    private void sumOfConsecutiveNumber(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        int p=1;
        long remainder=0;
        int sum,count=0,j=1,k=1,a=0;
        long N=0;
        int[] result=new int[T+1];
        for(int i=0;i<T;i++){
            N=scanner.nextLong();
            //System.out.println(N);
            count=0;
            for(j=1;j<=(N+1)/2;j++){
                sum=0;
                for(k=j;sum<N;k++){
                    sum+=k;
                    if(sum==N){
                        count++;
                        //System.out.print(N+"=");
                        //for(a=j;a<k;a++)System.out.print(a+"+");
                        //System.out.println(k);
                    }
                }
            }
            result[i]=count;
        }

        for(int r=0;r<T;r++){
            int id=r+1;
            System.out.println("Case #"+id+": "+result[r]);
        }
    }
    private void sumOfConsecutiveNumber2(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        long j=1,a=0;
        int count=0,k=1;
        long N=0;
        int[] result=new int[T+1];
        for(int i=0;i<T;i++){
            N=scanner.nextLong();
            //System.out.println(N);
            count=0;
            /*
             * 遍询k使存在j有N=(j+j+k-1)*k/2
             * */
            for(k=2;k<=Math.sqrt(2*N);k++){
                if(N*2%k==0){
                    if((N*2/k+1-k)%2==0&&(N*2/k+1-k)/2>0){
                        j=(N*2/k+1-k)/2;
                        count++;
                        System.out.print(N+"=");
                        for(a=j;a<j+k-1;a++)System.out.print(a+"+");
                        System.out.println(j+k-1);
                    }
                }
            }
            result[i]=count;
        }

        for(int r=0;r<T;r++){
            int id=r+1;
            System.out.println("Case #"+id+": "+result[r]);
        }
    }

    /*(BJTU)Infinity的卡牌：成对的卡牌，遗落一张，找出被遗落的卡牌号*/
    private void findCard(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        int T=scanner.nextInt(),m,n,a[],i,result;
        //System.out.println("T："+T);
        boolean flag;
        for(int k=0;k<T;k++) {
            n=scanner.nextInt();
            a=new int[n-1];
            for(i=0;i<n-1;i++)a[i]=scanner.nextInt();
            Arrays.sort(a);
            //for(i=0;i<n-1;i++)System.out.println("a[" + i + "]: " + a[i]);
            result=0;
            flag=false;
            for(i=0;i<n-2;i+=2){
                if(a[i]!=a[i+1]){
                    flag=true;
                    result=a[i];
                    break;
                }
            }
            if(!flag)result=a[n-2];
            System.out.println("Case #" + (k + 1) + ": " + result);
        }
    }

    /*(BJTU)魔法
    * 学历仅包括初级魔法、中级魔法和高级魔法三门课程的成绩情况，用百分制表达。如果一位魔法师在某门课程上及格 (>=60 分 ) 的话，他就能得到相应的职称并担任对应的职业。当然，有高级职称的人可以担任低级职业。输入数据第一行为一个正整数 T ，表示测试数据的组数。 接下来是 T 组测试数据，每组测试数据的第一行为一个整数 n ，表示简历份数，随后的 n 行中，每行以低级、中级、高级的顺序表示三门课的成绩（ 1≤T≤100 ， 1≤n≤1000 ， 0≤ 成绩 ≤100 ）。 对于每一组输入数据，输出一行形如 ”Case #id: a b c” 的结果 , 表示第 id 组数据结果是 a,b,c ， id 从 1 开始， a,b,c 表示三种人的数量。
    * */
    private void scoreGrading() {
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        long j=0;
        long N=0,a,b,c;
        int count_a=0,count_b=0,count_c=0;
        int[] result_a=new int[T];
        int[] result_b=new int[T];
        int[] result_c=new int[T];
        for(int i=0;i<T;i++){
            N=scanner.nextLong();//输入简历数
            //System.out.println(N);
            count_a=0;count_b=0;count_c=0;
            for(j=0;j<N;j++){
                a=scanner.nextLong();
                b=scanner.nextLong();
                c=scanner.nextLong();
                //System.out.println(a+b+c);
                if(c>=60){
                    count_a++;
                    count_b++;
                    count_c++;
                }else if(b>=60){
                    count_a++;
                    count_b++;
                }else if(a>=60)count_a++;
            }
            result_a[i]=count_a;
            result_b[i]=count_b;
            result_c[i]=count_c;
        }

        for(int r=0;r<T;r++){
            int id=r+1;
            System.out.println("Case #"+id+": "+result_a[r]+" "+result_b[r]+" "+result_c[r]);
        }
    }

    /*(BJTU)calfcamel的2333
     *给定一个小于 60 位的整数 p ，求大于 p 的最小的数 p1 ，使得 p1 中包含数 2333 。
     * */
    private void bigNumber(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        long a,b=0,x,y,z,temp;
        long N,p;
        int flag=0;
        int id,j,count;
        long[] result=new long[T];
        for(int i=0;i<T;i++){
            N=scanner.nextLong();//输入一个位数小于60位的整数
            //System.out.println(N);
            flag=0;
            count=0;
            temp=N;
            do{
                count++;//位数统计
                temp/=10;
            }while(temp>0);

            if(count>=4){
                for(j=4;j<=count;j++){
                    a=N%(long)Math.pow(10,j);
                    b=N/(long)Math.pow(10,j);
                    //System.out.println(a/(long)pow(10,j-4));
                    if(a/(long)Math.pow(10,j-4)==2333){flag=1;break;}//如果已存在2333
                    else if(a<2334*Math.pow(10,j-4)-1){flag=2;break;}//从后往前与2333比较，如果小于则补全
                }
                //System.out.println(flag);
                //System.out.println(j);
                z=(N/10000+1)*10000+2333;
                if(flag==1&&N%(long)Math.pow(10,j-4)+1!=(long)Math.pow(10,j-4)){x=N+1;p=Math.min(x,z);}
                else if(flag==2){y=b*(long)Math.pow(10,j)+2333*(long)Math.pow(10,j-4);p=Math.min(y,z);}
                else p=(N/10000+1)*10000+2333;
            }else p=2333;
            //System.out.println(p);
            id=i+1;
            System.out.println("Case #"+id+": "+p);
        }
    }
    private void bigNumber2(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        int id;
        long N,p,temp;
        boolean flag=false;
        for(int i=0;i<T;i++){
            N=scanner.nextLong();//输入一个位数小于60位的整数
            //System.out.println(N);
            temp=N;
            do{
                temp++;//从N开始逐渐加1
                if(Long.toString(temp).contains("2333")) flag=true;
                else flag=false;
            }while(!flag);
            p=temp;
            //System.out.println(p);
            id=i+1;
            System.out.println("Case #"+id+": "+p);
        }
    }
    private void bigNumber3(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        int id;
        BigInteger N,p,temp,add=new BigInteger("1");
        /*BigInteger N=new BigInteger("2"),p,temp;
        BigInteger add=new BigInteger("1");
        N.add(add);
        System.out.println(add+""+N.add(add));*/
        String s;
        boolean flag=false;
        for(int i=0;i<T;i++){
            N=new BigInteger(scanner.next());//输入一个位数小于60位的整数
            //System.out.println(N);
            temp=N.add(add);
            s=temp.toString();
            //System.out.println(s.contains("2333"));
            while (!s.contains("2333")){
                temp=temp.add(add);//从N开始逐渐加1
                s=temp.toString();
                //System.out.println(s);
            }
            p=temp;
            //System.out.println(p);
            id=i+1;
            System.out.println("Case #"+id+": "+p);
        }
    }
    private void bigNumber4(){
        BigInteger bi1 = new BigInteger("123456789") ;	// 声明BigInteger对象
        BigInteger bi2 = new BigInteger("987654321") ;	// 声明BigInteger对象
        System.out.println("加法操作：" + bi2.add(bi1)) ;	// 加法操作
        System.out.println("减法操作：" + bi2.subtract(bi1)) ;	// 减法操作
        System.out.println("乘法操作：" + bi2.multiply(bi1)) ;	// 乘法操作
        System.out.println("除法操作：" + bi2.divide(bi1)) ;	// 除法操作
        System.out.println("最大数：" + bi2.max(bi1)) ;	 // 求出最大数
        System.out.println("最小数：" + bi2.min(bi1)) ;	 // 求出最小数
        BigInteger result[] = bi2.divideAndRemainder(bi1) ;	// 求出余数的除法操作
        System.out.println("商是：" + result[0] + "；余数是：" + result[1]) ;

        /*BigInteger abs () 返回大整数的绝对值
        BigInteger add (BigInteger val)返回两个大整数的和
        BigInteger and (BigInteger val)返回两个大整数的按位与的结果
        BigInteger andNot (BigInteger val)返回两个大整数与非的结果
        BigInteger divide (BigInteger val)返回两个大整数的商
        double doubleValue () 返回大整数的double类型的值
        float floatValue () 返回大整数的float类型的值
        BigInteger gcd (BigInteger val)返回大整数的最大公约数
        int intValue () 返回大整数的整型值
        long longValue () 返回大整数的long型值
        BigInteger max (BigInteger val)返回两个大整数的最大者
        BigInteger min (BigInteger val)返回两个大整数的最小者
        BigInteger mod (BigInteger val)用当前大整数对val求模
        BigInteger multiply (BigInteger val)返回两个大整数的积
        BigInteger negate () 返回当前大整数的相反数
        BigInteger not () 返回当前大整数的非
        BigInteger or (BigInteger val)返回两个大整数的按位或
        BigInteger pow ( int exponent)返回当前大整数的exponent次方
        BigInteger remainder (BigInteger val)返回当前大整数除以val的余数
        BigInteger leftShift ( int n)将当前大整数左移n位后返回
        BigInteger rightShift ( int n)将当前大整数右移n位后返回
        BigInteger subtract (BigInteger val)返回两个大整数相减的结果
        byte[] toByteArray (BigInteger val)将大整数转换成二进制反码保存在byte数组中
        String toString () 将当前大整数转换成十进制的字符串形式
        BigInteger xor (BigInteger val)返回两个大整数的异或*/

        /*int array[];
        array=new int[3];
        System.out.println("array["+2+"]："+array[2]);*/
    }

    /*
     *求mRNA的反密码子tRNA
     * */
    private void tRNA(){
        //System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        //int T=Integer.parseInt(scanner.nextLine());
        int T=scanner.nextInt();
        //System.out.println("T："+T);
        int id,position,length;
        String s;
        boolean flag=false;
        for (int i = 0; i < T; i++) {
            s = scanner.next();//输入一个位数小于60位的整数
            length=s.length();
            /*for (position=-1;position<length;) {
                if(position==(length-1))break;
                position = s.indexOf("A", position + 1);
                System.out.println(position);
                s=s.substring(0,position)+"U"+s.substring(position+1);
                //System.out.println(s);
            }*/
            /*以上代码功能相当于s.replace("A","U");*/
            for(position=0;position<length;position++){
                switch (s.charAt(position)){
                    case 'A':s=s.substring(0,position)+"U"+s.substring(position+1);break;
                    case 'U':s=s.substring(0,position)+"A"+s.substring(position+1);break;
                    case 'C':s=s.substring(0,position)+"G"+s.substring(position+1);break;
                    case 'G':s=s.substring(0,position)+"C"+s.substring(position+1);break;
                    default:;
                }
            }
            id = i + 1;
            System.out.println("Case #" + id + ": " + s);
        }
    }
}
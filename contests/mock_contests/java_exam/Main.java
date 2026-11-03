import java.util.*;

class Product{
    private String name;
    private double price;
    private int likes;
    private int stock;
    private int sales;
    Product(String name,double price,int stock)
    {
        this.name=name;
        this.price=price;
        this.stock=stock;
    }
    public int getLikes() {
        return likes;
    }
    public int getSales() {
        return sales;
    }
    public int getStock() {
        return stock;
    }
    public void like() {
        likes++;
    }

    public void sale(){
        if(stock<=0) {
            System.out.println("库存不足");
        }
        else{
            System.out.printf("购买一件商品，请支付%.2f元。\n",price);
            stock--;
            sales++;
        }
    }

    public void sale(int num){
        if(stock>=num){
            System.out.printf("购买%d件商品，请支付%.2f元。\n",num,num*price);
            sales+=num;
            stock-=num;
        }
        else{
            System.out.println("库存不足");
        }
    }
    public String toString() {
        return "创建一个商品：商品名"+this.name+", 点赞数="+this.likes+", 价格="+this.price+", 库存="+this.stock+", 销量="+this.sales+"。";
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            String name = sc.next();
            if(name.equals("None")){

                //sc.close();
                break;
            }
            double price = sc.nextDouble();
            int stock = sc.nextInt();
            Product p = new Product(name,price,stock);
            System.out.println(p);
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            for(int i =  1;i<=a;i++){
                p.like();
            }
            if(b==1)p.sale();
            else{
                p.sale(b);
            }
            if(c==1)p.sale();
            else{
                p.sale(c);
            }
            System.out.printf("操作之后：%d %d %d\n", p.getLikes(), p.getStock() ,p.getSales());
        }
    }
}

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
/* Mini Project based on ATM system -------
                            check Balance
                            cash withdrawl
                            user Details 
                            update mobile number 

*/
class ATM{


private:
    long int acc_No;
    string name;
    int PIN;
    double balance;
    string mob_No;

public:
     void setter(long int a_N,string n,int P,double b,string m_N){
        acc_No = a_N;
        name = n;
        PIN = P;  
        balance = b;
        mob_No  = m_N ;
     }

     long int getAccountno(){
        return acc_No;
     }

     string getName(){
        return name;
     }

     int getPIN(){
        return PIN;
     }
    double getbalance(){
        return balance;
    }
    string getMobileno(){
        return mob_No;
    }

    void cashWithdrawl(int amt){
        if(amt>0 && amt<balance){
            balance -= amt;
            cout<<endl<<" Please Collect Your Cash";
            cout<<endl<<" Available balance :"<<balance;
            getch();
        }
        else{
            cout<< " Invalid Number Or Insufficient Balance";
            getch();
        }
    }

    void setMobile(string oldnum,string newnum){
        if(oldnum == mob_No){
            mob_No = newnum;
            cout<<endl<<" Mobile Number Updated Sucessfully  ";
            getch();
        }
        else{
            cout<<endl<<" Invalid Old Number";
            getch();
        }
    }

  
};





int main(){
   
  int choice =0, enterPIN;
  long int enterAccNo;  // pin and accno is used for user authentication

  system("cls");

  ATM user1;
  user1.setter(34776019,"Harshit",7810,450476.34,"8081491462");

     system("cls");
  do{
    

    cout<< endl<<" --- Welcome To ATM----"<<endl;
    cout<<endl<<" Enter Your Account Number ";
    cin>>enterAccNo;
    cout<<endl<<" Enter PIN ";
    cin>>enterPIN;

    if(enterAccNo == user1.getAccountno() && enterPIN == user1.getPIN()){
        do{
             int amount =0;
             string oldno,newno;

             system("cls");  // user interface
             cout<<endl<<"--- Welcome To ATM----"<<endl;
             cout<<endl<<"Select Options ";
             cout<<endl<< "1. Check Balance";
             cout<<endl<<"2. Cash withdrawl";
             cout<<endl<<"3. Show User Details";
             cout<<endl<<"4. Update Mobile Number";
             cout<<endl<<"5.EXIT"<<endl;
             cin>>choice;

             switch (choice)
             {
             case 1:
                cout<<"Your Bank Balance is : "<<user1.getbalance();
                getch();
            break;

            case 2: 
               cout<<" Enter the amount :";
               cin>>amount;
               user1.cashWithdrawl(amount);
            break;

            case 3:
               cout<<endl<<" ---User Details are :---";
               cout<<endl<<" -- Account Number "<<user1.getAccountno();
               cout<<endl<<" --Name            "<<user1.getName();
               cout<<endl<<" --Balance          "<<user1.getbalance();
               cout<<endl<<" --Mobile No        "<<user1.getMobileno();

               getch();
            break;

            case 4:
            cout<<endl<<" Enter old Mobile Number";
            cin>>oldno;

            cout<<endl<<" Enter new Mobile Number";
            cin>>newno;

            user1.setMobile(oldno,newno);
            break;

            case 5:
            exit(0);

             default:
             cout<<endl<<" Enter Valid choice !!!!";
                break;
             }

        }while(1);
    }
     else{
        cout<<endl<<" Invalid acc no or PIN"<<endl;
    }


  }while(1);

 

}

#include <iostream>
#include <cstring>

using namespace std;

char plate[15];
int i,digits,letters;
string type;
bool capital;

int main()
{
    //B071754
    //B16152
    //GL1235
    //GL05635
    //B20MOS
    //B165MOS
    //0123456
    cout<<"Enter your plate (without spacing): ";
    cin>>plate;

    for(i=0; i<=strlen(plate); i++)
        plate[i]=toupper(plate[i]);

    for(i=0; i<=strlen(plate); i++)
    {
        if(isdigit(plate[i]))
            digits++;
    }

    if(isdigit(plate[1]))
        capital = true;
    else
        capital = false;

    if(capital)
    {
        if(digits>3)
        {
            if(plate[1]=='0')
                type = "Provisional";
            else
                type = "Temporary";
        }
        else
            type = "Private";
    }
    else
    {
        if(digits>2)
        {
            if(plate[2]=='0')
                type = "Provisional";
            else
                type = "Temporary";
        }
        else
            type = "Private";
    }

    cout<<"Your plate: "<<plate<<endl;
    cout<<"Plate type: ";
    if(plate[1]=='A')
        cout<<"Ministry of Internal Affairs";
    else if(plate[0]=='C' && plate[1]=='D')
        cout<<"Diplomatic Corps";
    else if(plate[0]=='T' && plate[1]=='C')
        cout<<"Consular Transport";
    else if(plate[0]=='C' && plate[1]=='O')
        cout<<"Official Corps";
    else if(plate[0]=='A' && isdigit(plate[1]))
        cout<<"Army";
    else if(isalpha(plate[8]))
        cout<<"Dealer";
    else
        cout<<type;
}

#include <iostream>
#include <string>
#include<iomanip>

using namespace std;
double rate=1.5;  //rate in Rupees(NTC rate)

struct CallRecord {
    string callerName;
    string callerNumber;
    string receiverNumber;
    double duration; // Duration of the call in minutes
    double cost;
    CallRecord* next;
    CallRecord* prev;
};

class TelephoneBillingSystem {
private:
    CallRecord* head;
    CallRecord* tail;
public:
    TelephoneBillingSystem() : head(NULL), tail(NULL) {}

    // Function to add a call record to the list
    void addCallRecord(const string& callerName, const string& callerNumber, const string& receiverNumber,double duration,double cost=0) {
        CallRecord* newRecord= new CallRecord;
        newRecord->callerName=callerName;
        newRecord->callerNumber=callerNumber;
        newRecord->receiverNumber = receiverNumber;
        newRecord->duration = duration;
        cost=rate*duration;
        newRecord->cost= cost;
        newRecord->next= NULL;

        if (head == NULL) {
            newRecord->prev= NULL;
            newRecord->next= NULL;
            head = tail = newRecord;
        }
        else {
            CallRecord* temp;
            temp=head;
            temp->prev=newRecord;
            newRecord->next=temp;
            newRecord->prev= NULL;
            head=newRecord;
            }
    }


    //search the call record of a particular user via caller number
    void searchCallRecords(const string searchKey){
            CallRecord* temp;
            temp=head;
            cout<<"CALL RECORDS OF CALLER NUMBER "<<searchKey<<endl;
            cout << "Caller Name: "
            << setw(20)<<
            "Caller Number: "
            << setw(20)<<
            "Receiver Number: "
            <<  setw(20)<<
            "Duration: "
            << setw(20) <<
            "Cost:(Rs)" << endl;
            while(temp!= NULL){
                if(temp->callerNumber==searchKey){
                    cout <<  temp->callerName
                    << setw(20)<<
                    temp->callerNumber
                    << setw(20)<<
                    temp->receiverNumber
                    <<  setw(20)<<
                    temp->duration<<" min"
                    << setw(20) <<
                    temp->cost << endl;
                }
                temp=temp->next;
            }
            cout<<"------------------------------------------------------END--------------------------------------------------------------"<<endl<<endl;
        }

    //display all the existing call records
    void displayCallRecords() {
        CallRecord* temp;
        temp = head;
        cout<<"ALL CALL RECORDS RECORDED"<<endl;
            cout << "Caller Name: "
            << setw(20)<<
            "Caller Number: "
            << setw(20)<<
            "Receiver Number: "
            <<  setw(20)<<
            "Duration: "
            << setw(20) <<
            "Cost:(Rs)" << endl;
                while (temp != NULL) {
                    cout <<  temp->callerName
                    << setw(20)<<
                    temp->callerNumber
                    << setw(20)<<
                    temp->receiverNumber
                    <<  setw(20)<<
                    temp->duration<<" min"
                    << setw(20) <<
                    temp->cost << endl;

                    temp = temp->next;
                }
            cout<<"------------------------------------------------------END--------------------------------------------------------------"<<endl<<endl;

    }


    void totalBillCalculator(const string searchKey){
        CallRecord* temp;
        temp= head;
        double totalAmount= 0;
            while(temp!= NULL){
                    if(temp->callerNumber==searchKey){
                        totalAmount= totalAmount+temp->cost;
                    }
                    temp=temp->next;
                }
            cout<<"CallerNumber: "<<searchKey<<setw(20)<<" "<<"Total Bill Amount: Rs."<<totalAmount<<endl;

            cout<<"------------------------------------------------------END--------------------------------------------------------------"<<endl<<endl;

    }


    // Destructor to free memory
    ~TelephoneBillingSystem() {
        CallRecord* current = head;
        while (current != NULL) {
            CallRecord* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    TelephoneBillingSystem billingSystem;

    // Adding some sample call records
    billingSystem.addCallRecord("Benit", "9861235432", "9840321456", 10.5);
    billingSystem.addCallRecord("Gourav", "9840340590", "9861235432", 7.2);
    billingSystem.addCallRecord("Aashis", "9860443523", "9840340590", 15.3);
    billingSystem.addCallRecord("Benit", "9861235432", "9861616368", 15.7);
    billingSystem.addCallRecord("Aashis", "9860443523", "9861616368", 30.1);

    // Displaying call records
    billingSystem.displayCallRecords();

    //searching the call record of a specific user
    billingSystem.searchCallRecords("9861235432");
    billingSystem.searchCallRecords("9860443523");

    //calculating the total bill amount of some sample call records
    billingSystem.totalBillCalculator("9861235432");
    billingSystem.totalBillCalculator("9860443523");
    billingSystem.totalBillCalculator("9840340590");

    return 0;
}

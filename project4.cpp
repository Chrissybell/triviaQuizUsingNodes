/*
* Xuechao Li
* Project4 practice
*/
// By: Christobel Nweke
//Libary imports.
#include <iostream>
using namespace std;

// GLobal variables
int num_of_questions = 0;


//Structure for creating a linked list that holds a trivia question,answer and point amount.

struct triva_node {
    string question;
    string answer;
    int point;
    triva_node *next;
};

//creates a pointer to triva_node.
typedef triva_node* ptr_node;
//Prototypes
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);
void Unit_Test();
//creates two versions.
#//define UNIT_TESTING
#define triva_quiz


int main() {
    string cont_Yes_No;
    int num_question_to_ask;
    //Unit_test();
    ptr_node node_list = new triva_node;
    //Creates a new trivia game /
    //Sets up three original questions/
    //Sets up loop for user to input his or her own questions.
    //Quiz questions are stored in linked list.
#ifdef triva_quiz
    init_question_list(node_list);
    cout << "*** Welcome to Chris's trivia quiz game ***\n";

    cout << "This quiz comes preloaded with 3 base questions\n";
    cout << "Would you like to add your own question?\n";
    cin >> cont_Yes_No;
    while(cont_Yes_No.compare("Yes") == 0) {
        add_question(node_list);
        cout << "Continue? (Yes/No):\n";
        cin >> cont_Yes_No;
        //getline(cin, cont_Yes_No);
    }

    /*
    cout << "How many questions would you like to ask?\n";
    cin >> num_question_to_ask;
    while(num_question_to_ask > 0) {
        ask_question(node_list, num_question_to_ask);
        num_question_to_ask--;
    }
    */
    cout << "How many questions would you like to ask?\n";
    cin >> num_question_to_ask;
    ask_question(node_list,num_question_to_ask);
    
    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
    

//This is start of Trivia quiz game.
//ask_question(node_list, num_of_questions);
//cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
//return 0;
}

#endif
//Method for testing
//#ifdef UNIT_TESTING
    //Unit_Test();
    //return 0;
//}

//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {
    //ptr_node cur_ptr;
    //ptr_node cur_ptr;
    //string bob;

    ptr_node cur_ptr = new triva_node;
    cur_ptr->question = "How long was the shortest war on record?\n";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;

    cur_ptr->next = new triva_node;
    q_list = cur_ptr;
    cur_ptr = q_list->next;
    num_of_questions++;

    cur_ptr->question = "What was Bank of America’s original name?\n";
    cur_ptr->answer = "BankofItaly";
    cur_ptr->point = 50;

    cur_ptr->next = new triva_node;
    cur_ptr = cur_ptr->next;
    num_of_questions++;

    cur_ptr->question = "What is the best-selling video game of all time?\n";
    cur_ptr->answer = "WiiSports";
    cur_ptr->point = 20;
    cur_ptr->next = NULL;
    num_of_questions++;



    /*
    ptr_node cur_ptr = new triva_node;
    cur_ptr->question = "How long was the shortest war on record?\n";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = cur_ptr;
    num_of_questions++;
    q_list = cur_ptr;
    
    ptr_node cur_ptr2 = new triva_node;
    cur_ptr2->question = "What was Bank of America’s original name?\n";
    cur_ptr2->answer = "BankofItaly";
    cur_ptr2->point = 50;
    //cur_ptr2->next = cur_ptr2;
    num_of_questions++;
    q_list->next = cur_ptr2;
    

   
    ptr_node cur_ptr3 = new triva_node;
    cur_ptr3->question = "What is the best-selling video game of all time?\n";
    cur_ptr3->answer = "WiiSports";
    cur_ptr3->point = 20;
    //cur_ptr2->next = cur_ptr3;
    num_of_questions++;
    q_list->next = cur_ptr3;
    q_list->next = NULL;
    */

  
   
}

//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
    //string answer;
    //string question;
    //int point;

    ptr_node new_ptr = new triva_node;
    //gets data from user.
    cout << "Enter a new question: \n";
    cin >> new_ptr->question;
    //getline(cin, new_ptr->question);
    
    //gets data from user.
    cout << "What is the answer?\n";
    cin >> new_ptr->answer;
    //getline(cin, new_ptr->answer);

    //gets data from user.
    cout << "How many points do you want it to be worth?\n";
    cin >> new_ptr->point;
    //getline(cin, new_ptr->point);

    new_ptr->next = q_list;
    q_list = new_ptr;
    num_of_questions++;

}

//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
    string user_answer;
    int total_point = 0;
    int right_point;
    ptr_node cur_ptr = new triva_node;
    cur_ptr = q_list;
    
    if (q_list == NULL) {
        return 0;
    }
    if(num_ask < 1) {
        
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.\n";
    }
    if(num_of_questions < num_ask) {
        cout << "Warning - There is only " << num_of_questions << " trivia in the list.\n";
    }

    else {
        for(int x = 0; x < num_ask; x++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            cin >> user_answer;
            //getline(cin, user_answer);
            if (user_answer.compare(cur_ptr->answer) == 0) { //correct_answer) {
                cout << "Your Answer is Correct\n";
                cout << "You earned " << cur_ptr->point << " Points from this question\n";
                right_point = cur_ptr->point;
                total_point = total_point + right_point;
               
                
            }
            
            else {
                cout << "Your Answer is Incorrect\n";
                cout << "You earned 0 Points from this question\n";
                total_point = total_point;
               
            }
            cur_ptr = cur_ptr->next;
            
        }
   
       
    }
    cout << "You earned " << total_point << " total points this round/n";
    return 0;
}

//Test cases to check whether the methods work.

void Unit_Test() {
    ptr_node node_list = new triva_node;
    init_question_list(node_list);

    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list, 0);
    cout << "\nCase 1 Passed\n\n";

    cout << "Unit Test Case 2: Ask 1 question in the linked list. an incorrect answer." << endl;
    ask_question(node_list, 1);
    cout << "\nCase 2 Passed\n\n";

    cout << "Unit Test Case 3: Ask 1 question in the linked list. a correct answer." << endl;
    ask_question(node_list, 1);
    cout << "\nCase 3 Passed\n\n";

    cout << "\n\n*** End of the Debugging Version ***";
}


//#endif
















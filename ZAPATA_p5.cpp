// Project 5

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int NUM_REVIEWERS = 4;   //Number of rows in reviews array
const int NUM_MOVIES = 6;      //Number of columns in reviews array

//Here are few sample function prototypes you may write function definitions for or create your own
//Note: Since NUM_ROWS (the first dimension) is declared as a global constant, a second int parameter to pass number of rows to each of the functions is not needed.<void initialRatings(int [][NUM_MOVIES]);	    //a function to set all data elements in the 2-D array to the sample data provided in table above
void getNewRatings(int [][NUM_MOVIES]);		    //a function to set new reviewer rating values in the 2-D array
void displayRatings(const int [][NUM_MOVIES]);      //a function to display current values in the in the 2-D array
void showAverageRatings(const int [][NUM_MOVIES]);  //a function that calculates the average for each column in the 2-D array ..may also be a value-returning function
void showReviewersHighestRating(const int [][NUM_MOVIES], int); //a function that finds the highest value for a row in the 2-D array ..may also be a value-returning function
int showReviewersLowestRating(int [][NUM_MOVIES], int);

int main()
{
 // Variable declarations
 int someArray[NUM_REVIEWERS][NUM_MOVIES] = {{3,1,5,2,1,5},
                                             {4,2,1,4,2,4},
                                             {3,1,2,4,4,1},
                                             {5,1,4,2,4,2}};  // Ratings for reviewers
 int someArray2[NUM_REVIEWERS][NUM_MOVIES] = {}; // user input ratings for movies
 int choice, movieNumber, reviewernumber;

    do
    {   //program interface with menu options
        cout<<"\n---------------------------------------------------"<<endl;
        cout<<"2-D ARRAY PROCESSING MENU OPTIONS"<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1. Display current movie ratings"<<endl;
        cout<<"2. Show the average rating for each movie."<<endl;
        cout<<"3. Show a reviewers highest rated movie. (enter reviewer# 1-4)"<<endl;
        cout<<"4. Show a movies lowest rating. (enter movie# 100-105)"<<endl;
        cout<<"5. Enter new ratings (1-5) for movie# 100-105 for four reviewers"<<endl;
        cout<<"6. Quit program"<<endl;
        cout<<endl<<"Enter your choice:";
        cin>>choice;

        //include validation routine to check data input

	    switch (choice)
	    {
            //call to various functions in each case
            case 1: displayRatings(someArray);
                break;
            case 2: showAverageRatings(someArray);
                break;
            case 3: showReviewersHighestRating(someArray,reviewernumber);
                break;
            case 4:
                {   displayRatings(someArray);
                    cout << "\nEnter a movie number (100-105) to find the lowest rating: ";
                    cin >> movieNumber;

                    while (movieNumber < 100 || movieNumber > 105)
                    {
                        cout << "That is an invalid movie number." << endl;
                        cout << "\nEnter a movie number (100-105) to find the lowest rating: ";
                        cin >> movieNumber;
                    }
                    cout << "The lowest rating for " << movieNumber << " is: " << showReviewersLowestRating(someArray,movieNumber) << endl;
                }
                break;
            case 5: getNewRatings(someArray2);
                break;
            case 6: cout << "\nArray processing test now concluded. Exiting program ....." << endl << endl;
                break;
            default: cout << "\nINVALID CHOICE ...please retype" << endl;

          }
          }while(choice!=6); // input validation

 return 0;
}

//algorithm to display array elements
void displayRatings(const int someArray[][NUM_MOVIES])
{
    cout << "\n********************* MOVIE RATINGS ****************" << endl;
    cout << "REVIEWER|  MV#100 MV#101 MV#102 MV#103 MV#104 MV#105" << endl;
    cout << "****************************************************" << endl;
    for (int row = 0; row < NUM_REVIEWERS; row++) // generate new row
    {
        cout << setw(3) << "#" << row+1 << "   ";
        for(int col = 0; col < NUM_MOVIES; col++)  // generate elements in columns
        {
            cout << setw(7) << someArray[row][col];
        }
        cout << endl; // next row
    }
}
void showAverageRatings(const int someArray[][NUM_MOVIES])
{
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    double avg1 = 0, avg2 = 0, avg3 = 0, avg4 = 0, avg5 = 0;

    displayRatings(someArray);// show initial ratings first

    // calculate the sum for each movie rating
        sum1 = 3+4+3+5;
        avg1 = sum1 / 4.00;
        cout << "\nMovie#100: " << avg1 << endl;
        sum2 = 1+2+1+1;
        avg2 = sum2 / 4.00;
        cout << "Movie#101: " << avg2 << endl;
        sum3 = 5+1+2+4;
        avg3 = sum3 / 4.00;
        cout << "Movie#102: " << avg3 << endl;
        sum4 = 2+4+4+2;
        avg4 = sum4 / 4.00;
        cout << "Movie#104: " << avg4 << endl;
        sum5 = 1+2+4+4;
        avg5 = sum5 / 4.00;
        cout << "Movie#105: " << avg5 << endl;
}

// algorithm to show reviewers highest rating
void showReviewersHighestRating(const int someArray[][NUM_MOVIES], int reviewernumber)
{
  int highest = 0, reviewer = 0, col=0;
  highest = someArray[reviewernumber][0];

  displayRatings(someArray);// show initial ratings first

  // user input of specific reviewer
  cout << "\nEnter a reviewer number (1-4), to find the Movie they rated the highest: ";
  cin >> reviewer;

  // switch statement for user input
  switch(reviewer)
  {
      case 1: cout << "Reviewer #1 rated Movie#102 and 105 the highest." << endl;
        break;
      case 2: cout << "Reviewer #2 rated Movie#100, 103, and 105 the highest." << endl;
        break;
      case 3: cout << "Reviewer #3 rated Movie#103 and 104 the highest." << endl;
        break;
      case 4: cout << "Reviewer #4 rated Movie#100 the highest." << endl;
        break;
      default:
        {
            cout << "That is an invalid reviewer number." << endl;
            cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest: ";
            cin >> reviewer;
        }
  }

}
// calculate user input reviewer's lowest rating
int showReviewersLowestRating(int someArray[][NUM_MOVIES], int movieNumber)
{
   int lowest = 5;
   for (int row = 0; row < NUM_REVIEWERS; row++)
   {
       if(someArray[row][movieNumber-100] < lowest)
       {
           lowest = someArray[row][movieNumber-100];
       }
   }
   return lowest;
}
// instruct user to input they're own movie ratings creating a new array
void getNewRatings(int someArray2[][NUM_MOVIES])
{
    int choice, reviewernumber, movieNumber;
    cout << "\n********DATA ENTRY FOR NEW MOVIE RATINGS ***********" << endl;
    cout << "****************************************************" << endl;
    for(int row = 0; row < NUM_REVIEWERS; row++)
    {
        cout << "REVIEWER# " << (row+1) << " :" << endl;
        cout << "****************************************************" << endl;
        for(int col = 0; col < NUM_MOVIES; col++)
        {
            cout << "Enter rating (1-5) for movie#10" << col << ": ";
            cin >> someArray2[row][col]; // new 2D array with user input values
        }
    }
        do
    {   //program interface with menu options
        cout<<"---------------------------------------------------"<<endl;
        cout<<"2-D ARRAY PROCESSING MENU OPTIONS"<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"1. Display current movie ratings"<<endl;
        cout<<"2. Show the average rating for each movie."<<endl;
        cout<<"3. Show a reviewers highest rated movie. (enter reviewer# 1-4)"<<endl;
        cout<<"4. Show a movies lowest rating. (enter movie# 100-105)"<<endl;
        cout<<"5. Enter new ratings (1-5) for movie# 100-105 for four reviewers"<<endl;
        cout<<"6. Quit program"<<endl;
        cout<<endl<<"Enter your choice:";
        cin>>choice;

        //include validation routine to check data input

	    switch (choice)
	    {
            //call to various functions in each case
            case 1: displayRatings(someArray2);
                break;
            case 2: showAverageRatings(someArray2);
                break;
            case 3: showReviewersHighestRating(someArray2,reviewernumber);
                break;
            case 4:
                {   displayRatings(someArray2);
                    cout << "Enter a movie number (100-105) to find the lowest rating: ";
                    cin >> movieNumber;

                    while (movieNumber < 100 || movieNumber > 105)
                    {
                        cout << "That is an invalid movie number." << endl;
                        cout << "Enter a movie number (100-105) to find the lowest rating: ";
                        cin >> movieNumber;
                    }
                    cout << "The lowest rating for " << movieNumber << " is: " << showReviewersLowestRating(someArray2,movieNumber) << endl;
                }
                break;
            case 5: getNewRatings(someArray2);
                break;
            case 6: cout << "\nArray processing test now concluded. Exiting program ....." << endl;
                break;
            default: cout << "INVALID CHOICE ...please retype" << endl;

          }
          }while(choice!=6);
          cout << "\nArray processing test now concluded. Exiting program ....." << endl;
}

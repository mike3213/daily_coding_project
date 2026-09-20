#include <iostream>
#include <vector>
using namespace std;
int main() {
    int num_tests = 0;
    cin >> num_tests;
    while(num_tests-- > 0) {
        int total_pages = 0, start_page = 0, desired_page = 0, scroll_pages = 0;
        cin >> total_pages >> start_page >> desired_page >> scroll_pages;
        int steps = -1;
        int diff_pages = desired_page - start_page;
        if(diff_pages < 0)
            diff_pages *= -1;
        if(diff_pages % scroll_pages == 0) {
            steps = diff_pages / scroll_pages;
            cout << steps;
        } else {
            //go to end or begin
            //for the begin
            int steps_of_begin = -1;
            if((desired_page - 1) % scroll_pages == 0) {
                int step1 = (start_page - 1) / scroll_pages;
                if((start_page - 1) % scroll_pages != 0)
                    step1 += 1;
                steps_of_begin = step1 + (desired_page - 1) / scroll_pages;
            }
            int steps_of_end = -1;
            if((total_pages - desired_page) % scroll_pages == 0) {
                int step1 = (total_pages - start_page) / scroll_pages;
                if((total_pages - start_page) % scroll_pages != 0)
                    step1 += 1;
                steps_of_end = step1 + (total_pages - desired_page) / scroll_pages;
            }
            if(steps_of_begin == -1 && steps_of_end == -1)
                cout << -1;
            else if(steps_of_begin != - 1 && steps_of_end != -1)
                cout << (steps_of_begin < steps_of_end ? steps_of_begin : steps_of_end);
            else {
                if(steps_of_begin != -1)
                    cout << steps_of_begin;
                else
                    cout << steps_of_end;
            }
        }

        if(num_tests != 0)
            cout << '\n';
    }

    return 0;
}
/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/

#include "Task_Manage.h"

/*---------- constructor ----------*/
Task_Manage::Task_Manage()
{
    today = Time::current_day();
    month = Time::current_month();
    create_days();
}

/*---------- create_days - inserts days into days vector ----------*/
void Task_Manage::create_days()
{
    int month_of_day = month;
    Day *day;
    for (int i = today; i <= NUM_DAYS[month_of_day - 1]; i++)
    {
        day = new Day(to_string(i) + "." + to_string(month_of_day));
        days.push_back(day);
    }
    if (month_of_day < December)
        month_of_day++;
    else
        month_of_day = January;
    for (int i = 1; i < today && i < NUM_DAYS[month_of_day - 1]; i++)
    {
        day = new Day(to_string(i) + "." + to_string(month_of_day));
        days.push_back(day);
    }
}

/*---------- update - checks if current day is different from today - if not - go back ----------
  ---------- else - updates days vector ----------*/
void Task_Manage::update()
{
    int current_day = Time::current_day();
    if (current_day == today)
        return;
    for (auto day : days)
        delete day;
    days.clear();
    today = current_day;
    int current_month = Time::current_month();
    if (month != current_month)
        month = current_month;
    create_days();
}

/*---------- day_location_list - gets string represents day and returns its location in days vector ----------*/
int Task_Manage::day_location_list(string &day)
{
    int searched_day = stoi(day);
    if (searched_day >= today)
        return searched_day - today;
    return NUM_DAYS[month - 1] - today + searched_day;
}

/*---------- menu - displays the Task Management options and gets from the user his choice ----------*/
void Task_Manage::menu()
{
    boolean sw_continue = true;
    int choice{};
    while (sw_continue)
    {
        system("CLS");
        Style::headline("TASK MANAGEMENT", true);
        cout << Style::HEADLINE_SPACE << "You can manage all your tasks for the next month\n";
        cout << "What would you preffer do ?";
        cout << Style::HEADLINE_SPACE;
        for (int i = 0; i < MENU_OPTIONS; i++)
        {
            cout << i << " - " << TASKS_MENU[i] << endl;
        }
        choice = Settings::insert_valid_choice("\nPlease enter your choice: ", MENU_OPTIONS);
        switch (choice)
        {
        case Return:
            return;
        case See:
            see_tasks();
            break;
        case Add:
            add_task();
            break;
        case Delete:
            remove_task();
            break;
        case Complete:
            complete_task();
            break;
        default:
            cout << Style::HEADLINE_SPACE;
            Style::wrong("Invalid choice !");
            Sleep(2000);
            break;
        }
    }
}

/*---------- complete_task - gets from the user a task from today to mark as completed ----------*/
void Task_Manage::complete_task()
{
    string task{};
    update();
    system("CLS");
    Style::headline("TODAY TASKS", true);
    cout << Style::HEADLINE_SPACE << Style::BORDER << "\nYour Tasks Are : " << Style::HEADLINE_SPACE;
    if (!days.at(0)->show_day())
        return;
    cout << Style::BORDER << Style::HEADLINE_SPACE;
    cout << "\nWhich task was completed ? ";
    getline(cin >> ws, task);
    days.at(0)->change_day(MARK, task);
}

/*---------- remove_task - gets from the user a day and a task from that day - and deletes it ----------*/
void Task_Manage::remove_task()
{
    string deleted_task{}, line{}, day{};
    int day_location{};
    update();
    system("CLS");
    Style::headline("REMOVE TASKS", true);
    day_input(day, "Please enter the day you would like to remove a task from : ");
    cout << Style::HEADLINE_SPACE << Style::BORDER << "\nYour Tasks Are : " << Style::HEADLINE_SPACE;
    day_location = day_location_list(day);
    if (!days.at(day_location)->show_day())
        return;
    cout << Style::BORDER << Style::HEADLINE_SPACE;
    cout << "Which task would you like to remove  ? ";
    getline(cin >> ws, deleted_task);
    days.at(day_location)->change_day(DELETE, deleted_task);
}

/*---------- add_task - gets from the user a day and a task - and adds the task to that day ----------*/
void Task_Manage::add_task()
{
    string day{}, new_task{};
    int day_location{};
    update();
    system("CLS");
    Style::headline("ADD TASKS", true);
    day_input(day, "please enter the day you would like to add a task to : ");
    day_location = day_location_list(day);
    cout << endl
         << "\nEnter your new task : ";
    getline(cin >> ws, new_task);
    days.at(day_location)->add_task(new_task);
}

/*---------- see_tasks - gets from the user a day and prints all the tasks he has ----------*/
void Task_Manage::see_tasks()
{
    string day{};
    int day_location{};
    update();
    system("CLS");
    Style::headline("YOUR TASKS", true);
    day_input(day, "please enter the day you would like to see : ");
    cout << Style::HEADLINE_SPACE << Style::BORDER << endl;
    day_location = day_location_list(day);
    cout << "Your Tasks Are :" << Style::HEADLINE_SPACE;
    days.at(day_location)->show_day();
    cout << endl
         << Style::BORDER << Style::HEADLINE_SPACE;
    cout << "Press any key to go back ";
    getch();
}

/*---------- day_input - checks if the user input is a valid day ----------*/
void Task_Manage::day_input(string &day, string phrase)
{
    boolean valid_day{};
    int integer_day{}, month_of_day{};
    do
    {
        cout << Style::HEADLINE_SPACE << phrase;
        getline(cin >> ws, day);
        day.erase(remove_if(day.begin(), day.end(), ::isspace), day.end());
        if (!Settings::is_number(day) || (integer_day = stoi(day)) < 1)
            valid_day = false;
        else
            valid_day = true;
        if (valid_day)
        {
            if (integer_day > today)
                month_of_day = month;
            else if (month == December)
                month_of_day = January;
            else
                month_of_day++;
            if (integer_day > NUM_DAYS[month_of_day - 1])
                valid_day = false;
        }
    } while (!valid_day);
    day = to_string(stoi(day));
}

~Task_Manage()
{
  for (auto day : days)
        delete day;
}

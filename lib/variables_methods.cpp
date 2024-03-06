#include "variables_methods.h"




string Container::rle_algorithm(string message) const{
    string compressed_string;
    int  size = message.size() - 1;
    for (int i = 0; i <= size; i++) {


        int count = 1;
        while (i <= size) {
            if (message[i] == message[i + 1]){
                count++;
                i++;
            }
            else
                break;
        }
        if (count == 1){
            compressed_string += message[i];
        }
        else{
            compressed_string += message[i];
            compressed_string += ";";
            compressed_string += to_string(count);
        }
    }
    return compressed_string;
    
}
string Container::switch_to_uppercase(string message)const
{
    for (unsigned int i = 0;i < message.size();i++)
    {
        if (message.at(i) >= 'a' && message.at(i) <= 'z')
        {
            message.at(i) -= 32;
        }
    }
    return message;
}
string Container::delete_spaces(string message)const
{

    string message_with_deleted_spaces;

    for (int i=0; i<message.size();i++) {
        if (message[i] != ' '){
            message_with_deleted_spaces += message[i];
        }
        else
            continue;
    }
    return message_with_deleted_spaces;
}
void Container::save_to_file(string message, string path)const
{
        
        
        fstream save;
        
        save.open("C:/Users/przem/Desktop/c++/vsc/main/"+path, ios_base::out);
        if (save.good()){
            save << message << endl;
            
            save.close();
        }
        else{
            cout << "nie dziala";
        }
    
    
}


void Container::menu()const {
        cout << "Welcome to a rle algorithm program, choose an option below"<< endl;
        cout << "[1] Type manually from keyboard" << endl;
        cout << "[2] Read from a data" << endl;
        cout << "[3] Exit program" << endl;
}

void Container::main_app()const{
    char choice, choice_2, choice_3;
    string message;
    bool loop = true;
    
    do
    {
        menu();
        cout << "Your choice:   ";
        cin>>choice;
        string rle_message, word, path, path_2, path_3, line; fstream read_from_file,save_from_file_2;
        
        switch (choice)
        {
            case '1':
                
                cout<< "Enter your message: ";
                std::cin.ignore();
                getline(cin,message);
                rle_message = rle_algorithm(switch_to_uppercase(delete_spaces(message))); 
                cout << rle_message << endl;
                cout << "Do you want to save your message to file? Type 'y' or 'n':"<<endl;
                cin >> choice_3;
                if (choice_3=='y'){
                    cout << "Enter a path to save file: ";
                    cin >> path_2;
                    save_to_file(rle_message, path_2);
                }
                else{
                   break; 
                }
            break;     
                
            case '2':
                cout << "You want to display or save to file? Type [1] if you want to display or [2] to save to a file: ";
                
                cin >> choice_2;
                cout << "Enter path to read from file (with .txt): ";
                cin >> path;
                read_from_file.open("C:/Users/przem/Desktop/c++/vsc/main/"+path, ios_base::in);
                if (choice_2 == '1'){
                    
                    while (getline(read_from_file,line)){
                        if (!line.empty()){
                            cout << rle_algorithm(switch_to_uppercase(delete_spaces(line))) << endl;
                        }
                        else{
                            continue;
                        }
                    }
                    read_from_file.close();
                }
                else if (choice_2 == '2')
                {
                    cout << "Enter a path to save file: ";
                    cin >> path_3;
                    
                    while (getline(read_from_file,line)){
                    
                            rle_message = rle_algorithm(switch_to_uppercase(delete_spaces(line)));
                            save_to_file(rle_message, path_3);
                        
                    }
                    read_from_file.close();
                    
                }
                
                
                break;
            case '3':
                cout << "You exited a program" << endl;
                loop=false;
                break;
            default:
                cout << "Error, type again";
                break;
    
        }
    } while (loop);
    
    
    
}


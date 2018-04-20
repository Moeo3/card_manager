#include <iostream>
#include <string>
#include <vector>
#include "time_.h"
using namespace std;

typedef vector<string> vecs;

class card {
    virtual bool pay(double money) = 0;
    virtual void query() = 0;
    virtual void deposit(double money) = 0;
};
class campus_card;

class deposit_card : card {
private:
    vecs _recode;
    string _card_id;
    string _release_day;
    string _owner;
    double _money;
    double _overdraft;
public:
    virtual bool pay(double money, string addr) {
        if (_money + _overdraft < money) return 0;
        _money -= money;
        string t = getTime();
        _recode.push_back(t + " pay " + to_string(money) + " at " + addr);
        return 1; 
    }
    virtual void query() {
        cout << "Records are as follows:" << endl; 
        for (auto iter = _recode.begin(); iter != _recode.end(); ++ iter) {
            cout << *iter << endl;
        }
    }
    virtual void deposit(double money, string from) {
        _money += money;
        string t = getTime();
        _recode.push_back(t + " deposit " + to_string(money) + " from " + from);
    }
    bool to_other_deposit_card(double money, deposit_card *card) {
        if (_money + _overdraft < money) return 0;
        _money -= money;
        string t = getTime();
        _recode.push_back(t + " pay " + to_string(money) + " to deposit card " + card->card_id());
        card->deposit(money, "deposit card " + _card_id);
        return 1; 
    }
    bool to_campus_card(double money, campus_card * card) {
        if (_money + _overdraft < money) return 0;
        _money -= money;
        string t = getTime();
        _recode.push_back(t + " pay " + to_string(money) + " to " + card->name() + "'s campus card " );
        card->deposit(money, "deposit card " + _card_id);
    }
    
    vecs recode() {
        return _recode;
    }
    string card_id() {
        return _card_id;
    }
    string release_day() {
        return _release_day;
    }
    string owner() {
        return _owner;
    }
    double overdraft() {
        return _overdraft;
    }
};

class campus_card : card {
private:
    vecs _recode;
    string _student_id;
    string _name;
    string _college;
    vector<deposit_card *> _bind;
    double _money;
public:
    virtual bool pay(double money) {

    }
    virtual void query() {

    }
    virtual void deposit(double money, string from) {

    }
    void bind(deposit_card * card) {
        _bind.push_back(card);
    }

    vecs recode() {
        return _recode;
    }
    string student_id() {
        return _student_id;
    }
    string name() {
        return _name;
    }
    string college() {
        return _college;
    }
    vector<deposit_card *> bind() {
        return _bind;
    }
};
class Solution {
public:
    vector<string> ans;
    void rec(string& num, int target, int index, string expression,
             long long value, long long last_operand) {
        if (index == num.size()) {
            if (value == target) {
                ans.push_back(expression);
            }
            return;
        }

        for (long long i = index; i < num.size(); i++) {
            bool is_zero = false;
            string new_num;
            if (num[index] == '0') {
                is_zero = true;
                // rec(num,target,i+1,expression+'+'+'0',value,0);
                // rec(num,target,i+1,expression+'-'+'0',value,0);
                // rec(num,target,i+1,expression+'*'+'0',(value-last_operand),0);
            }
            new_num = num.substr(index, i - index + 1);
            long long new_number = stoll(new_num);
            rec(num, target, i + 1, expression + '+' + to_string(new_number),
                value + (new_number), new_number);
            rec(num, target, i + 1, expression + '-' + to_string(new_number),
                value - (new_number), -new_number);
            rec(num, target, i + 1, expression + '*' + to_string(new_number),
                (value - last_operand) + (last_operand * (new_number)),
                last_operand * (new_number));
            if (is_zero)
                break;
        }
    }
    vector<string> addOperators(string num, int target) {
        bool is_zero = false;
        for (long long i = 0; i < num.size(); i++) {
            if (num[0] == '0') {
                is_zero = true;
                // rec(num,target,i+1,expression+'+'+'0',value,0);
                // rec(num,target,i+1,expression+'-'+'0',value,0);
                // rec(num,target,i+1,expression+'*'+'0',(value-last_operand),0);
            }
            long long new_number = stoll(num.substr(0, i - 0 + 1));
            rec(num, target, i + 1, to_string(new_number), new_number,
                new_number);
            if (is_zero)
                break;
        }
        return ans;
    }
};
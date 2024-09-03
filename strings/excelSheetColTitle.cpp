class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str = "";
        while (columnNumber > 0) {
            int index = (columnNumber - 1) % 26;
            str = char('A' + index) + str;
            columnNumber = (columnNumber - 1) / 26;
        }
        return str;
    }
};
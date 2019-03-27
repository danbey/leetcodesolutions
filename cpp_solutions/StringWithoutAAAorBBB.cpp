class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ret_str;
        ret_str.resize(A+B);
        int idx = 0;
        if (A+B < 3)
            return "ab";
        
        char biggest_char = 'a';
        int biggest = A;
        char smallest_char = 'b';
        int smallest = B;
        if (A < B) {
            biggest_char  = 'b';
            biggest = B;
            smallest_char = 'a';    
            smallest = A;
        }
        
        for (int i = A+B; i > 0; --i) {
            if (biggest == 0) {
                ret_str[idx++] = smallest_char;
                smallest--;
                continue;
            }

            if (smallest == 0) {
                ret_str[idx++] = biggest_char;
                biggest--;
                continue;
            }

            if (smallest == biggest) {
                ret_str[idx++] = smallest_char;
                ret_str[idx++] = biggest_char;
                smallest--;
                biggest--;
                i--;
                continue;
            }

            if (i % 3 == 0) {
                ret_str[idx++] = smallest_char;
                smallest--;
            } else {
                ret_str[idx++] = biggest_char;
                biggest--;
            }
        }

        return ret_str;
    }
};

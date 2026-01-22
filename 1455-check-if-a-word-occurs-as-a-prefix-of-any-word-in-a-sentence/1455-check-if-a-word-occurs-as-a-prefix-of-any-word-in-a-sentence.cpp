class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // break words whenever a single space comes
        //then for each word, check this
        for(int i=0,j=1;i<sentence.size();i++)
        {
            int k=0;

            while(i<sentence.size() && sentence[i]==searchWord[k])
            {
                i++;
                k++;
            }

            if(k==searchWord.size())
            {
                return j;
            }
            
            while(i<sentence.size() && sentence[i]!=' ')
            {
                i++;
            }

            j++;
        }

        return -1;

    }
};
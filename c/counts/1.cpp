#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<iostream>
#include<limits>
#include<climits>
#include<algorithm>

using namespace std;

string s;
vector<string> vs;
vector<int> vs1;
map<char,int> first;


int get_count(int value, int values[26]) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (value == values[i]) {
            count++;
        }
    }
    return count;
}
string isValid(string s) {
    int char_counts[26] = {0};
    
    for (int i = 0; i < s.size(); i++ ) {
        char_counts[s[i]-'a']++;
    }
    int max_count = INT_MIN; int min_count = INT_MAX;
    int max_count_increments = 0, min_count_increments = 0;
    for (int i = 0; i < 26; i++) {

        cout << i << ":" << char_counts[i] << endl;
        
        if (char_counts[i] > 0 && max_count < char_counts[i]) {
            max_count = char_counts[i];
        }
        if (char_counts[i] > 0 && min_count > char_counts[i]) {
            min_count = char_counts[i];
        }
    }
    if (max_count == min_count) {
        return "YES";
    } 
    max_count_increments = get_count(max_count, char_counts);
    min_count_increments = get_count(min_count, char_counts);
    
    if (max_count_increments == 1 && max_count == min_count+1 ) {
        return "YES";
    } 
    if (min_count_increments == 1) {
        return "YES";
    }
    return "NO";

}

string my_s = "ebhcgicceggecgdcibbeicigehhebabiehbdgaeaigihghbhigihfebgabicbgfhhedgbfehiahchcecedffhccebifcbdfcfaecicafahfiecceeaabbecfhgbfifabbffadcieeaiidddhfdeccaedbgcfdehbadihheieidgcfbdiiicgahebfbbdfeffegbdhgdagefhbgafaabfghdcbfdhabhfahbdhgifbghhafcieachcbeabccbiigdcfegcccfafehegbiecbdhabcffggiifaabfagbfdfbfacdcafabccgibiidgabiabigbgbbaideeagaaffcddhieicehhchfedfgbgbfhgedhacegaieeedggacbbgadeibbbcdhbabbieibcfbhgdbbiecdhbffaghhchhddcihgdgbgdcfgfggeaahffgiddeadgcegaiddhhdgagdidgacafececiebeigcbdfaedibbgbhciihcdifbacdagfbcefifefchhddadeaiegbfaidbeebiefghfghhdabdeegabagfbbdgbeaiiigeaadhbgebedddfihagdeiccdbcfchgadhgfaidaebfabbagdghebgagbfhfbgeagdgecbhfchebdgafceaffabagedbhcgcedaecdbiifefchcbgfbbibhiahchhfadffeacfbgeigaccedadaafhcieficdfhfheibfdhbgbfhhdfcghabacggchchbdaigbcihhdbifcdeggicgacehebadbdaibhdciefdgfhfeggdhgcaeeeidfebbaicgagcaiachffhadbddhhdbcehciagfdgeadidfcaaiafeadefbbbaidgiagbeacchbdaifgccgcfigefcachiiggbghfhbifciafgfigaabidhdgffcbgicbidibacbgfhddafbegdaagbhddceeifecciddigfiehdbdabahgaechf";

string my_s1 = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";

string my_s2 = "kjthvjaocsubczaufuxffhpijpdyvfluuppurmfkofqtalalzjwwzizcfzqrriwlylwenrvkpredbmgoibxhbanjcnlfyjadyxxbgcpgnlxxaslvoaivzvlwoziopscuvguyfnblfyxdskrflypbbktvjvgtnpagpusubqlzqsefwmfznkuiaoxbwtjomwyynmuvcqxncrrboxorhduajyaomcvopeuayniinolovpnjfbqvflojffrfwuxssflvvuuoombbwvzgomkuxwicmnioyrfdosblqhwylntjihhwiffbzutbhbeqvoogsktlsqtvccoevhqkyjsrfqnknpuglglzhrcpxnlaurmtuvxndojasxensjuundrpeepbpvgfujnccqawmshfoeffccsgsqpivlvzkkgfdmalcfcwdaeaokqjrkfomkkhxmuflpaepxfddmyktxjhuvpaqlwldbceeocjqlacvjlsazigbxumclepzgchiaxxkwnoehlxwfwzgcfxvojvjcmhbsvybsfwwijtndlnwpojbzdzzdwkmudcoslyfqdavxzddxskdxtzzkwcdvwgefjuderixjmzaqrkviioxikatujepfsxvbwtpsaalswtvqkmnsjhdpqeiyovijdxmsfseofgxncuvjiwrbdjpmnjpmotsvwaltaizzeqqpninjizekfwuzzpjzljwvukfktcujsvktoxpiblzfvhkwkpnrhzzrfiamjopyqpljiyqsvkgwoylbzvvcdkwgnddjjxmgsvgcvmvfuuymkztqigmeyzaxjvtxpeewoqrrrodgezjhcmcbiapytkhtiplznmwtsjexlzqutinspkvcbhsbfqccoojvukvmdralzpgxunqwowkqeelaynzuouyopogyjgffraiiklzwcvdrqbnnahprowonswawikuhovahddkmqhylwvwfybzqypqxqyhvptzhfhxdypshboefpjz";

main() {

    
    cout << isValid(my_s) << endl;
    cout << isValid(my_s1) << endl;
    cout << isValid(my_s2) << endl;
}

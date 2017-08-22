#include <iostream>
#include <string>
#include <map>
using namespace std;

// method1
enum cmd{
    CMD_UNSPEC = 200,
    CMD_ADD,
    CMD_SUB,
    CMD_MULTI,
    CMD_DIV,
};

static inline const char* cmd_str(enum cmd c, int base){
    static const char* strings[] = {"CMD_UNSPEC", "CMD_ADD", "CMD_SUB", "CMD_MULTI", "CMD_DIV",};
    return strings[c-base];
}

// method2
map<cmd, string> g_StaticMapCMDValue2String;

void InitCMD()
{
    g_StaticMapCMDValue2String[CMD_UNSPEC] = "CMD_UNSPEC";
    g_StaticMapCMDValue2String[CMD_ADD] = "CMD_ADD";
    g_StaticMapCMDValue2String[CMD_SUB] = "CMD_SUB";
    g_StaticMapCMDValue2String[CMD_MULTI] = "CMD_MULTI";
    g_StaticMapCMDValue2String[CMD_DIV] = "CMD_DIV";
}

int main()
{
    cout << cmd_str(CMD_ADD, 200)<< endl;

    InitCMD();
    cout << g_StaticMapCMDValue2String[CMD_ADD] <<endl;

    return 0;
}

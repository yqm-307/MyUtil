#pragma once

#include <string>
#include <vector>

namespace YUtil::File
{


class FileRead
{
public:
    /**
     * @brief 读取文件内所有内容
     * @param path 文件名
     * @param ref 入参
     * @return true 读取成功
     * @return false 读取失败
     */
    static bool ReadFile(const char * path,std::string& ref);
    
private:    
    FileRead();
    ~FileRead();
};

}
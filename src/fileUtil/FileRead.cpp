#include "FileRead.h"
#include "src/Logger/Logger.h"
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>
#include <unistd.h>

using namespace YUtil::File;

bool FileRead::ReadFile(const char* path,std::string& ret)
{
    int opfd = ::open(path,O_RDONLY);//只读打开
    if(opfd<0)
    {
        ERROR("%s ,open file '%s' error",__FUNCTION__,path);
    }
    else
    {
        //获取文件信息
        struct stat file_stat;
        if(0>fstat(opfd,&file_stat))
        {
            ERROR("%s ,get file stat error",__FUNCTION__);
        }
        int file_len = file_stat.st_size;
        ret.resize(file_len);
        char* p = &(*ret.begin());    //取固定大小内存头部指针，没问题
        int readsize = 0;               //已读
        while(readsize<file_len)
        {
            int save = errno;
            int n = ::read(opfd,(p+readsize),file_len-readsize);
            if(n<0)
            {
                if(errno == EAGAIN)
                    continue;
                WARN("%s ,::read errno: %d",__FUNCTION__,errno);
                errno = save;
            }
            else
                readsize+=n;
        }//read over
        close(opfd);
        assert(file_len == ret.size());
        return true;
    }
    return false;

}



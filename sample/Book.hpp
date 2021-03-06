#pragma once
#include <string>
#include "Types.h"

/** 本の情報 */
class Book {
private:
	/** 蔵書番号 */
    int64 id_;
    
    /** 題名 */
    std::string title_;

public:
	/** */
    Book( int64 id, std::string title )
        : id_(id), title_(title)
    {
    }
    
    /** 蔵書番号の取得 */
    int64 id() const { return id_; }

    /** 題名の取得 */
    const std::string& title() const { return title_; }
};

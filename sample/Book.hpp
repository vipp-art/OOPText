#pragma once
#include <string>
#include "Types.h"

/** �{�̏�� */
class Book {
private:
	/** �����ԍ� */
    int64 id_;
    
    /** �薼 */
    std::string title_;

public:
	/** */
    Book( int64 id, std::string title )
        : id_(id), title_(title)
    {
    }
    
    /** �����ԍ��̎擾 */
    int64 id() const { return id_; }

    /** �薼�̎擾 */
    const std::string& title() const { return title_; }
};

#pragma once
#include <string>
#include "Types.h"

/** –{‚Ìî•ñ */
class Book {
private:
	/** ‘ ‘”Ô† */
    int64 id_;
    
    /** ‘è–¼ */
    std::string title_;

public:
	/** */
    Book( int64 id, std::string title )
        : id_(id), title_(title)
    {
    }
    
    /** ‘ ‘”Ô†‚Ìæ“¾ */
    int64 id() const { return id_; }

    /** ‘è–¼‚Ìæ“¾ */
    const std::string& title() const { return title_; }
};

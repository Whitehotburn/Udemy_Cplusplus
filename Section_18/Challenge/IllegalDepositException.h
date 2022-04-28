#ifndef __ILLEGAL_DEPOSIT_EXCEPTION_H__
#define __ILLEGAL_DEPOSIT_EXCEPTION_H__

class IllegalDepositException : public std::exception
{
public:
    IllegalDepositException() noexcept = default;
    ~IllegalDepositException() = default;
    virtual const char* what() const noexcept {
        return "Illegal deposit exception";
    }
};

#endif // __ILLEGAL_DEPOSIT_EXCEPTION_H__

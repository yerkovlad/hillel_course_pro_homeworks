#ifndef TRANSACTIONVISITOR_H
#define TRANSACTIONVISITOR_H

#include "Transaction.h"

class TransactionVisitor {
public:
    virtual void visit(Deposit &deposit) = 0;
    virtual void visit(Withdrawal &withdrawal) = 0;
    virtual void visit(Transfer &transfer) = 0;
    virtual void visit(BillPayment &billPayment) = 0;
    virtual ~TransactionVisitor() = default;
};

#endif
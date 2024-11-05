#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class TransactionVisitor;

class Transaction {
public:
    virtual void accept(TransactionVisitor &visitor) = 0;
    virtual ~Transaction() noexcept = default;
};

class Deposit : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override final;
};

class Withdrawal : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override final;
};

class Transfer : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override final;
};

class BillPayment : public Transaction {
public:
    void accept(TransactionVisitor &visitor) override final;
};

#endif
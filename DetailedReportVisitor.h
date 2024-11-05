#ifndef DETAILEDREPORTVISITOR_H
#define DETAILEDREPORTVISITOR_H

#include "TransactionVisitor.h"

class DetailedReportVisitor : public TransactionVisitor {
public:
    void visit(Deposit &deposit) override final;
    void visit(Withdrawal &withdrawal) override final;
    void visit(Transfer &transfer) override final;
    void visit(BillPayment &billPayment) override final;
};

#endif
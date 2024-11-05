#include "ShortReportVisitor.h"
#include <iostream>

void ShortReportVisitor::visit(Deposit &deposit) {
    std::cout << "Short report: Deposit transaction.\n";
}

void ShortReportVisitor::visit(Withdrawal &withdrawal) {
    std::cout << "Short report: Withdrawal transaction.\n";
}

void ShortReportVisitor::visit(Transfer &transfer) {
    std::cout << "Short report: Transfer transaction.\n";
}

void ShortReportVisitor::visit(BillPayment &billPayment) {
    std::cout << "Short report: Bill payment transaction.\n";
}
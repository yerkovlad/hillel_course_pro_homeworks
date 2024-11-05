#include "DetailedReportVisitor.h"
#include <iostream>

void DetailedReportVisitor::visit(Deposit &deposit) {
    std::cout << "Detailed report: Deposit transaction with full details.\n";
}

void DetailedReportVisitor::visit(Withdrawal &withdrawal) {
    std::cout << "Detailed report: Withdrawal transaction with full details.\n";
}

void DetailedReportVisitor::visit(Transfer &transfer) {
    std::cout << "Detailed report: Transfer transaction with full details.\n";
}

void DetailedReportVisitor::visit(BillPayment &billPayment) {
    std::cout << "Detailed report: Bill payment transaction with full details.\n";
}
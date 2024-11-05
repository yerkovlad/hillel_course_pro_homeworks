#include "Transaction.h"
#include "ShortReportVisitor.h"
#include "DetailedReportVisitor.h"

int main() {
    Deposit deposit;
    Withdrawal withdrawal;

    ShortReportVisitor shortReport;
    DetailedReportVisitor detailedReport;

    deposit.accept(shortReport);
    deposit.accept(detailedReport);

    withdrawal.accept(shortReport);
    withdrawal.accept(detailedReport);

    return 0;
}
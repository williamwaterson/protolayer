#include "TitledWindow.h"

namespace protolayer
{

namespace carbon
{

// Explicit Template Instantiation
template class TitledWindow <kDocumentWindowClass>;
template class TitledWindow <kMovableAlertWindowClass>;
template class TitledWindow <kMovableModalWindowClass>;
template class TitledWindow <kFloatingWindowClass>;
template class TitledWindow <kUtilityWindowClass>;
template class TitledWindow <kSheetWindowClass>;
template class TitledWindow <kToolbarWindowClass>;
template class TitledWindow <kSheetAlertWindowClass>;

}

}

@interface CocoaLineEdit : NSTextField <NSTextFieldDelegate> {
@public
  phoenix::LineEdit* lineEdit;
}
-(id) initWith:(phoenix::LineEdit&)lineEdit;
-(void) textDidChange:(NSNotification*)n;
-(IBAction) activate:(id)sender;
@end

namespace phoenix {

struct pLineEdit : public pWidget {
  LineEdit& lineEdit;
  CocoaLineEdit* cocoaLineEdit = nullptr;

  Size minimumSize();
  void setBackgroundColor(Color color);
  void setEditable(bool editable);
  void setForegroundColor(Color color);
  void setText(string text);
  string text();

  pLineEdit(LineEdit& lineEdit) : pWidget(lineEdit), lineEdit(lineEdit) {}
  void constructor();
  void destructor();
};

}

#ifndef KEY_H
#define KEY_H

#include <QString>
#include "SDImage.h"

class QTimer;
class Key;
class DeckView;
class KeyDelegate {
    virtual void press(Key *key) = 0;
};

class Key {
public:
    Key();
    bool operator==(const Key &other);

private:
    QString _identifier;
    DeckView *_parent;
    QTimer *_longPressTimer = nullptr;
    bool _isLongPressing = false;
    SDImage *_image;//: ? = SDImage(color: .clear).resize(newSize: CGSize(width: 96, height: 96))
    SDImage *_longPressImage = nullptr;
    KeyDelegate *delegate;
    bool enabled = false;

  /*  var refresh: (()->())? = nil
    var customIdentifier: String? = nil*/
  // let position: DeckPoint
/*
    init(parent: View, position: DeckPoint) {
        self._parent = parent
        self.position = position
    }

    var status: KeyStatus {
        set {
            if (_status == .up && newValue == .down) {
                //todo: user selector
                _longPressTimer = Timer.scheduledTimer(withTimeInterval: 2, repeats: false) { (_) in
                    self.startedLongPressing()
                }
            }
            else {
                if (_longPressTimer != nil && _longPressTimer!.isValid) {
                    _longPressTimer?.invalidate()
                    _longPressTimer = nil
                }

                if (_status == .down && newValue == .up) {
                    delegate?.press(for: self)
                }
            }
            _status = newValue
        }
        get { _status }
    }

    //The default image for unpressed state
    var defaultImage: SDImage? {
        set {
            _image = newValue
        }
        get { _image }
    }

    //the image for a long press state
    var longPressImage: SDImage? {
        set {
            _longPressImage = newValue
        }
        get { _longPressImage }
    }

    QPixmap currentImageState: SDImage {
        guard _image != nil else {
            return SDImage(color: .clear)
        }

        if (_status == .up && defaultImage != nil) {
            return defaultImage!
        } else {
            if (!_isLongPressing && defaultImage != nil) {
                return SDImage(color: .clear)
                    .resize(newSize: CGSize(width: 96, height: 96))
                    .add(newImage: defaultImage!.rotate(orientation: .up).add(backgroundImage: nil))
            }

            if (_isLongPressing && longPressImage != nil) {
                return SDImage(color: .clear)
                    .resize(newSize: CGSize(width: 96, height: 96))
                    .add(newImage: longPressImage!)
            }
        }

        return SDImage(color: .black)
    }
*/
private signals:
    void startedLongPressing();
    void stoppedLongPressing();
    void clicked();
};

#endif // KEY_H

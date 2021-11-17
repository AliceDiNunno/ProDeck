#ifndef SDIMAGE_H
#define SDIMAGE_H

#include <QMap>
#include <QString>
#include <QPixmap>
#include <QUrl>
#include "sdimageorientation.h"
#include "TextPosition.h"

class SDImage {
private:
    bool _colorIsClear;
    QPixmap _image;
    SDImageOrientation _orientation;
    QSize _newSize;
    SDImage *backgroundImage;
    SDImage *topMostImage;
    QMap<TextPosition, QString> text;

    SDImage(QString path) {
        _colorIsClear = false;

        auto imagePath = QUrl("file://" + path);

        auto image = QPixmap(imagePath.toString());

        _image = image;
    }

    SDImage(QColor color) {
        if (color == Qt::transparent) {
            _colorIsClear = true;
        } else {
            _colorIsClear = false;
        }

        auto image = QPixmap(96, 96);

        image.fill(color);
        _image = image;
    }
/*
    void rotate(orientation: CGImagePropertyOrientation) -> SDImage {
        self.orientation = orientation
        return self
    }

    SDImage resize(QSize newSize) {
        _newSize = newSize
        return this
    }

    SDImage add(newImage SDImage) {
        self.topMostImage = newImage
        return self
    }

    SDImage add(backgroundImage SDImage) {
        self.backgroundImage = backgroundImage
        return self
    }

    func add(text: String, to: TextPosition) {
        self.text[to] = text
    }

    func render() -> CIImage? {
        var image = self.image.copy() as! CIImage

        if (newSize != nil || topMostImage != nil || backgroundImage != nil) {
            let originalImage = UIImage(ciImage: image)
            let originalImageSize = originalImage.size
            var newRect = CGRect.zero

            //resizing
            if let newSize = newSize {
                //calculating ratio of new size
                let width = newSize.width / originalImageSize.width
                let height = newSize.height / originalImageSize.height

                let aspectRatio = max(width, height)

                newRect.size.width = originalImageSize.width * aspectRatio
                newRect.size.height = originalImageSize.height * aspectRatio
                newRect.origin.x = 0
                newRect.origin.y = 0
            }
            let drawSize = (newSize == nil) ? originalImageSize : newSize!

            var backgroundImageRepresentation: UIImage? = nil

            var topImageRepresentation: UIImage? = nil
            var topImageMargin: CGFloat? = nil

            //adding image on background
            if let backgroundImage = backgroundImage {
                let backgroundImageData = backgroundImage.render()
                guard backgroundImageData != nil else {
                    print("SDImage: Unable to render background image")
                    return nil
                }

                backgroundImageRepresentation = UIImage(ciImage: backgroundImageData!)
            }


            //adding image on top
            if let topMostImage = topMostImage {
                let topImageData = topMostImage.render()
                guard topImageData != nil else {
                    print("SDImage: Unable to render topmost image")
                    return nil
                }

                topImageRepresentation = UIImage(ciImage: topImageData!)
                topImageMargin = drawSize.width * 0.1
            }

            //drawing
            UIGraphicsBeginImageContext(drawSize)

            //background
            if (backgroundImageRepresentation != nil) {
                backgroundImageRepresentation!.draw(in: CGRect(origin: CGPoint(x: 0, y: 0),
                                                               size: CGSize(width: drawSize.width, height: drawSize.height)))
            }

            //key
            if (!colorIsClear) {
                if (newSize != nil && newRect != .zero) {
                    originalImage.draw(in: newRect)
                }
            }

            //text
            for (key, str) in text {
                let paragraphStyle = NSMutableParagraphStyle()

                let attrs = [NSAttributedString.Key.font: UIFont(name: "HelveticaNeue", size: 20)!, NSAttributedString.Key.paragraphStyle: paragraphStyle, NSAttributedString.Key.foregroundColor: UIColor(ciColor: .white)]

                let string: NSAttributedString = NSAttributedString(string: str, attributes: attrs)

                let textX: CGFloat = (96 - string.width(containerHeight: 96)) / 2
                var textY: CGFloat

                switch (key) {
                case .center:
                    textY = (96 - string.height(containerWidth: 96)) / 2
                    break
                case .bottom:
                    textY = 96 - string.height(containerWidth: 96)
                    break
                default:
                    textY = 0
                }

                string.draw(with: CGRect(x: textX,
                                        y: textY,
                                        width: 96,
                                        height: 96),
                            options: .usesLineFragmentOrigin,
                            context: nil)
            }

            //foreground
            if (topImageRepresentation != nil && topImageMargin != nil) {
                topImageRepresentation!.draw(in:
                    CGRect(origin: CGPoint(x: topImageMargin!, y: topImageMargin!),
                          size: CGSize(width: drawSize.width - topImageMargin! * 2, height: drawSize.height - topImageMargin! * 2) ))
            }


            let buffer = UIGraphicsGetImageFromCurrentImageContext()

            UIGraphicsEndImageContext()

            guard buffer != nil else {
                print("SDImage: Unable to draw image")
                return nil
            }

            var newImage = CIImage(image: buffer!)

            guard newImage != nil else {
                print("SDImage: Unable to convert image")
                return nil
            }

            image = newImage!
        }

        if (orientation != nil) {
            image = image.oriented(orientation!)
        }

        return image
    }*/
};

#endif // SDIMAGE_H

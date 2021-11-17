#ifndef VIEWSPLITTERVERTICALLY_H
#define VIEWSPLITTERVERTICALLY_H

#include "OS/DeckView.h"

class ViewSplitterVertically: DeckView, ViewDelegate {
    /*func utilityKeyPressed() {

    }

    func utilityKey() -> Key? {
        nil
    }

    var masterView: View? = nil
    var detailView: View? = nil

    override init(navigationManager: NavigationManager, rect: CGRect) {
        super.init(navigationManager: navigationManager, rect: rect)
        delegate = self
    }

    override func viewDidLoad() {

    }

    func toPoint(index: Int, inside: CGRect? = nil) -> CGPoint {
        var insideRect = CGRect()
        if (inside == nil) {
            insideRect = frame
        } else {
            insideRect = inside!
        }
        return CGPoint(x: Int(CGFloat(index).truncatingRemainder(dividingBy: insideRect.width)),
                       y: Int(CGFloat(index) / insideRect.width))
    }

    func findViewForKey(at: DeckPoint) -> View? {
        let keyPosition = CGPoint(x: Int((CGFloat(at.absolutePosition).truncatingRemainder(dividingBy: self.frame.width))),
                                      y: Int((CGFloat(at.absolutePosition) / self.frame.width) ))

        let masterViewBounds = CGRect(x: 0, y: 0, width: masterView?.frame.width ?? 0, height: masterView?.frame.height ?? 0)

        if (masterViewBounds.contains(keyPosition)) {
            return masterView
        } else {
            return detailView
        }
    }

    func relativePosition(for index: DeckPoint) -> Int {
        let subView = findViewForKey(at: index)
        guard subView != nil else {
            return index.absolutePosition
        }
        let sizeDifference = CGSize(width: frame.width - subView!.frame.width, height: frame.height - subView!.frame.height)

        let absolutePosition = toPoint(index: index.absolutePosition)

        return index.absolutePosition - Int(absolutePosition.y * sizeDifference.width) - Int(subView!.frame.origin.x)
    }

    void key(DeckPoint pos) -> Key? {
        let viewForKey = findViewForKey(at: pos)//?.delegate?.key(at: at)
        guard viewForKey != nil else {
            return nil
        }
        let pos = DeckPoint(absolutePosition: relativePosition(for: pos), context: viewForKey!.frame)

        return viewForKey!.delegate?.key(at: pos)
    }*/
};

#endif // VIEWSPLITTERVERTICALLY_H

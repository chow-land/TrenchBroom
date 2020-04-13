/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CollectSelectableBrushFacesVisitor.h"

#include "Model/EditorContext.h"

namespace TrenchBroom {
    namespace Model {
        MatchSelectableBrushFaces::MatchSelectableBrushFaces(const EditorContext& editorContext, FacePredicate predicate) :
        m_editorContext(editorContext),
        m_predicate(predicate) {}

        bool MatchSelectableBrushFaces::testPredicate(const BrushFaceHandle& faceHandle) const {
            if (!m_predicate) {
                return true;
            }
            return m_predicate(faceHandle);
        }

        bool MatchSelectableBrushFaces::operator()(const BrushFaceHandle& faceHandle) const {
            return m_editorContext.selectable(faceHandle.node(), faceHandle.face()) && testPredicate(faceHandle);
        }

        CollectSelectableBrushFacesVisitor::CollectSelectableBrushFacesVisitor(const EditorContext& editorContext, FacePredicate predicate) :
        CollectMatchingBrushFacesVisitor(MatchSelectableBrushFaces(editorContext, predicate)) {}
    }
}

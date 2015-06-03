
//
// @COPYRIGHT@
//
// $Id: ReferenceDetector.java,v 1.1 2004/12/17 15:35:46 archiecobbs Exp $
//

package org.dellroad.jc.cgen.analysis;

import java.util.*;
import org.dellroad.jc.cgen.*;
import soot.*;
import soot.jimple.*;

/**
 * Instances of this class detect 'new' expressions of
 * objects that subclass <code>java.lang.ref.Reference</code>.
 * The result is either <code>Boolean.TRUE</code>
 * or <code>Boolean.FALSE</code>.
 */
public class ReferenceDetector extends AbstractJimpleValueSwitch {

	public void caseNewExpr(NewExpr v) {
		SootClass sc = v.getBaseType().getSootClass();
		while (true) {
			if (sc.getName().equals("java.lang.ref.Reference")) {
				setResult(Boolean.TRUE);
				return;
			}
			if (!sc.hasSuperclass())
				break;
			sc = sc.getSuperclass();
		}
		setResult(Boolean.FALSE);
	}

	public void defaultCase(Object obj) {
		setResult(Boolean.FALSE);
	}
}


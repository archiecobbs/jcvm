
//
// @COPYRIGHT@
//
// $Id: FinalizeDetector.java,v 1.1 2004/12/17 15:35:46 archiecobbs Exp $
//

package org.dellroad.jc.cgen.analysis;

import java.util.*;
import org.dellroad.jc.cgen.*;
import soot.*;
import soot.jimple.*;

/**
 * Instance of this class detect 'new' expressions of objects that
 * override finalize(). The result is either <code>Boolean.TRUE</code>
 * or <code>Boolean.FALSE</code>.
 */
public class FinalizeDetector extends AbstractJimpleValueSwitch {

	public void caseNewExpr(NewExpr v) {
		SootClass sc = v.getBaseType().getSootClass();
		SootMethod finalize = sc.getMethod("finalize",
		    Collections.EMPTY_LIST, VoidType.v());
		setResult(Boolean.valueOf(
		    !finalize.getDeclaringClass().getName()
		      .equals("java.lang.Object")));
	}

	public void defaultCase(Object obj) {
		setResult(Boolean.FALSE);
	}
}


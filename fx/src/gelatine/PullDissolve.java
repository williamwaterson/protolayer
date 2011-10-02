package org.protolayer.space.transitions;

import org.protolayer.space.scene.*;
import org.protolayer.space.space.*;

/**
 * <p>
 * @author William Waterson
 * @version $Revision: 1.1.1.1 $
 */
public class PullDissolve
  implements Transition
{
  /** The total time period for the overall transition */
  private static final long UNITY = 1;

  /** The total time period for the overall transition */
  private static final long ZERO = 0;

  /** The total time period for the overall transition */
  private boolean _inProgress;

  /** The total time period for the overall transition */
  private float[] _startPosition = new float[3];

  /** The total time period for the overall transition */
  private float[] _startTarget = new float[3];

  /** TODO: Documentation */
  private float[] _finalStartPosition = new float[3];

  /** TODO: Documentation */
  private float[] _finalStartTarget = new float[3];

  /** The total time period for the overall transition */
  private float[] _targetPosition = new float[3];

  /** The total time period for the overall transition */
  private float[] _transitionDirection = new float[3];

  /** The total time period for the overall transition */
  private float[] _transitionDirection2 = new float[3];

  /** The total time period for the overall transition */
  private float[] _displacement = new float[3];

  /** The total time period for the overall transition */
  private long _timeStarted;

  /** The time elapsed since the transition was commenced */
  private long _timeElapsed;

  /** The total time period for the overall transition */
  private long _timePeriod;

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  public PullDissolve(long timePeriod)
  {
    _inProgress = false;
    _timePeriod = timePeriod;
    _timeElapsed = ZERO;
    _timeStarted = ZERO;
  }

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  public void setTargetPoint(float x, float y, float z)
  {
    _targetPosition[0] = x;
    _targetPosition[1] = y;
    _targetPosition[2] = z;
  }

  /**
   * Returns true if the transition has commenced.
   * <p>
   */
  public boolean inProgress()
  {
    return _inProgress;
  }

  /**
   * Performs a single increment in the transition from the initial scene
   * to the final scene according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial scene to the final
   * scene.
   * <p>
   * @param initialScene
   *
   * @param finalScene
   *
   */
  public void commence(SceneView initialView, SceneView finalView)
  {
    // Estimate the camera transition direction for the initial scene
    _startPosition[0] = initialView.getModel().getCameraModel()._position[0];
    _startPosition[1] = initialView.getModel().getCameraModel()._position[1];
    _startPosition[2] = initialView.getModel().getCameraModel()._position[2];

    _startTarget[0] = initialView.getModel().getCameraModel()._target[0];
    _startTarget[1] = initialView.getModel().getCameraModel()._target[1];
    _startTarget[2] = initialView.getModel().getCameraModel()._target[2];

    _transitionDirection[0] = _targetPosition[0];
    _transitionDirection[1] = _targetPosition[1];
    _transitionDirection[2] = _targetPosition[2];

    _transitionDirection[0] -= _startPosition[0];
    _transitionDirection[1] -= _startPosition[1];
    _transitionDirection[2] -= _startPosition[2];

    // Obtain orthonormal basis of first camera
    float[][] orthoBasis = new float[3][3];
    orthoBasis[0] = new float[3];
    orthoBasis[1] = new float[3];
    orthoBasis[2] = new float[3];

    orthoBasis[0][0] = initialView.getModel().getCameraModel()._target[0];
    orthoBasis[0][1] = initialView.getModel().getCameraModel()._target[1];
    orthoBasis[0][2] = initialView.getModel().getCameraModel()._target[2];

    orthoBasis[0][0] -= initialView.getModel().getCameraModel()._position[0];
    orthoBasis[0][1] -= initialView.getModel().getCameraModel()._position[1];
    orthoBasis[0][2] -= initialView.getModel().getCameraModel()._position[2];
    normalise(orthoBasis[0]);

    float[] orient = initialView.getModel().getCameraModel()._orient;
    crossProduct(orthoBasis[0], orient, orthoBasis[1]);
    orthoBasis[1][0] = -orthoBasis[1][0];
    orthoBasis[1][1] = -orthoBasis[1][1];
    orthoBasis[1][2] = -orthoBasis[1][2];
    normalise(orthoBasis[1]);

    crossProduct(orthoBasis[0], orthoBasis[1], orthoBasis[2]);

    // Determine the direction vector relative to the camera orthonormal basis
    float[][] transpose = new float[3][3];

    transpose[0][0] = orthoBasis[0][0];
    transpose[0][1] = orthoBasis[1][0];
    transpose[0][2] = orthoBasis[2][0];

    transpose[1][0] = orthoBasis[0][1];
    transpose[1][1] = orthoBasis[1][1];
    transpose[1][2] = orthoBasis[2][1];

    transpose[2][0] = orthoBasis[0][2];
    transpose[2][1] = orthoBasis[1][2];
    transpose[2][2] = orthoBasis[2][2];

    inverse(transpose, orthoBasis);

    float[] result = new float[3];
    multiply(orthoBasis, _transitionDirection, result);

    // Obtain orthonormal basis of second camera
    orthoBasis[0][0] = finalView.getModel().getCameraModel()._target[0];
    orthoBasis[0][1] = finalView.getModel().getCameraModel()._target[1];
    orthoBasis[0][2] = finalView.getModel().getCameraModel()._target[2];

    orthoBasis[0][0] -= finalView.getModel().getCameraModel()._position[0];
    orthoBasis[0][1] -= finalView.getModel().getCameraModel()._position[1];
    orthoBasis[0][2] -= finalView.getModel().getCameraModel()._position[2];
    normalise(orthoBasis[0]);

    orient = finalView.getModel().getCameraModel()._orient;
    crossProduct(orthoBasis[0], orient, orthoBasis[1]);
    orthoBasis[1][0] = -orthoBasis[1][0];
    orthoBasis[1][1] = -orthoBasis[1][1];
    orthoBasis[1][2] = -orthoBasis[1][2];
    normalise(orthoBasis[1]);

    crossProduct(orthoBasis[0], orthoBasis[1], orthoBasis[2]);

    transpose[0][0] = orthoBasis[0][0];
    transpose[0][1] = orthoBasis[1][0];
    transpose[0][2] = orthoBasis[2][0];

    transpose[1][0] = orthoBasis[0][1];
    transpose[1][1] = orthoBasis[1][1];
    transpose[1][2] = orthoBasis[2][1];

    transpose[2][0] = orthoBasis[0][2];
    transpose[2][1] = orthoBasis[1][2];
    transpose[2][2] = orthoBasis[2][2];

    // Determine the start point for the final scene's camera
    multiply(transpose, result, _finalStartPosition);

    _transitionDirection2[0] = finalView.getModel().getCameraModel()._position[0];
    _transitionDirection2[1] = finalView.getModel().getCameraModel()._position[1];
    _transitionDirection2[2] = finalView.getModel().getCameraModel()._position[2];

    _transitionDirection2[0] -= _finalStartPosition[0];
    _transitionDirection2[1] -= _finalStartPosition[1];
    _transitionDirection2[2] -= _finalStartPosition[2];

    _finalStartPosition[0] = -_finalStartPosition[0];
    _finalStartPosition[1] = -_finalStartPosition[1];
    _finalStartPosition[2] = -_finalStartPosition[2];

    _finalStartPosition[0] += finalView.getModel().getCameraModel()._position[0];
    _finalStartPosition[1] += finalView.getModel().getCameraModel()._position[1];
    _finalStartPosition[2] += finalView.getModel().getCameraModel()._position[2];

    _finalStartTarget[0] = finalView.getModel().getCameraModel()._target[0];
    _finalStartTarget[1] = finalView.getModel().getCameraModel()._target[1];
    _finalStartTarget[2] = finalView.getModel().getCameraModel()._target[2];

    _finalStartTarget[0] -= finalView.getModel().getCameraModel()._position[0];
    _finalStartTarget[1] -= finalView.getModel().getCameraModel()._position[1];
    _finalStartTarget[2] -= finalView.getModel().getCameraModel()._position[2];

    _finalStartTarget[0] += _finalStartPosition[0];
    _finalStartTarget[1] += _finalStartPosition[0];
    _finalStartTarget[2] += _finalStartPosition[0];

    // Estimate the camera start point for the final scene
    //    _finalStartPosition[0] = finalView.getModel().getCameraModel()._position[0];
    //_finalStartPosition[1] = finalView.getModel().getCameraModel()._position[1];
    //_finalStartPosition[2] = finalView.getModel().getCameraModel()._position[2];

    //_finalStartPosition[0] -= _transitionDirection[0];
    //_finalStartPosition[1] -= _transitionDirection[1];
    //_finalStartPosition[2] -= _transitionDirection[2];

    // Trigger starting of the transition
    _timeStarted = System.currentTimeMillis();
    _inProgress = true;
  }

  /**
   * Performs a single increment in the transition from the initial scene
   * to the final scene according to the particular transition type
   * implemented by the derived class. The method applies a visitor
   * pattern to the transition from the initial scene to the final
   * scene.
   * <p>
   * @param initialScene
   *
   * @param finalScene
   *
   */
  public void increment(SceneView initialView, SceneView finalView)
  {
    long timeCurrent = System.currentTimeMillis();
    _timeElapsed = timeCurrent - _timeStarted;
    float fraction = ((float) _timeElapsed) / ((float) _timePeriod);

    if (fraction > UNITY) {
      _inProgress = false;
    } else {
      initialView.getModel().getCameraModel()._alpha = UNITY - fraction;
      finalView.getModel().getCameraModel()._alpha = fraction;

      _displacement[0] = _transitionDirection[0];
      _displacement[1] = _transitionDirection[1];
      _displacement[2] = _transitionDirection[2];

      _displacement[0] *= fraction;
      _displacement[1] *= fraction;
      _displacement[2] *= fraction;

      initialView.getModel().getCameraModel()._position[0] = _startPosition[0];
      initialView.getModel().getCameraModel()._position[1] = _startPosition[1];
      initialView.getModel().getCameraModel()._position[2] = _startPosition[2];

      initialView.getModel().getCameraModel()._position[0] += _displacement[0];
      initialView.getModel().getCameraModel()._position[1] += _displacement[1];
      initialView.getModel().getCameraModel()._position[2] += _displacement[2];

      initialView.getModel().getCameraModel()._target[0] = _startTarget[0];
      initialView.getModel().getCameraModel()._target[1] = _startTarget[1];
      initialView.getModel().getCameraModel()._target[2] = _startTarget[2];

      initialView.getModel().getCameraModel()._target[0] += _displacement[0];
      initialView.getModel().getCameraModel()._target[1] += _displacement[1];
      initialView.getModel().getCameraModel()._target[2] += _displacement[2];

      //      _displacement[0] = _transitionDirection2[0];
      //_displacement[1] = _transitionDirection2[1];
      //_displacement[2] = _transitionDirection2[2];

      //      _displacement[0] *= fraction;
      //_displacement[1] *= fraction;
      //_displacement[2] *= fraction;

      //      finalView.getCameraModel()._position[0] = _finalStartPosition[0];
      //finalView.getCameraModel()._position[1] = _finalStartPosition[1];
      //finalView.getCameraModel()._position[2] = _finalStartPosition[2];

      //      finalView.getCameraModel()._position[0] += _displacement[0];
      //      finalView.getCameraModel()._position[1] += _displacement[1];
      //  finalView.getCameraModel()._position[2] += _displacement[2];

      //      finalView.getCameraModel()._target[0] = _finalStartTarget[0];
      //finalView.getCameraModel()._target[1] = _finalStartTarget[1];
      //finalView.getCameraModel()._target[2] = _finalStartTarget[2];

      //      finalView.getCameraModel()._target[0] += _displacement[0];
      //finalView.getCameraModel()._target[1] += _displacement[1];
      //finalView.getCameraModel()._target[2] += _displacement[2];
    }

  }

  /**
   * TODO: Documentation
   * <p>
   */
  public void postComplete(SceneView initialView, SceneView finalView)
  {
    initialView.getModel().getCameraModel()._alpha = UNITY;
    finalView.getModel().getCameraModel()._alpha = UNITY;

    initialView.getModel().getCameraModel()._position[0] = _startPosition[0];
    initialView.getModel().getCameraModel()._position[1] = _startPosition[1];
    initialView.getModel().getCameraModel()._position[2] = _startPosition[2];

    finalView.getModel().getCameraModel()._position[0] = _finalStartPosition[0];
    finalView.getModel().getCameraModel()._position[1] = _finalStartPosition[1];
    finalView.getModel().getCameraModel()._position[2] = _finalStartPosition[2];

    finalView.getModel().getCameraModel()._position[0] += _transitionDirection2[0];
    finalView.getModel().getCameraModel()._position[1] += _transitionDirection2[1];
    finalView.getModel().getCameraModel()._position[2] += _transitionDirection2[2];

    _timeElapsed = ZERO;
    _timeStarted = ZERO;
  }

  /**
   * TODO: Documentation
   * <p>
   */
  private void evaluateOrthonormalBasis()
  {
  }

  /**
   * TODO: Documentation
   * <p>
   */
  private void inverse(float[][] a, float[][] inv)
  {
    float det  =  a[0][0] * (a[2][2] * a[1][1] - a[2][1] * a[1][2]) -
	a[1][0] * (a[2][2] * a[0][1] - a[2][1] * a[0][2]) +
	a[2][0] * (a[1][2] * a[0][1] - a[1][1] * a[0][2]);

    inv[0][0] =   a[2][2] * a[1][1] - a[2][1] * a[1][2];
    inv[0][1] = -(a[2][2] * a[0][1] - a[2][1]* a[0][2]);
    inv[0][2] =   a[1][2] * a[0][1] - a[1][1] * a[0][2]; 

    inv[1][0] = -(a[2][2] * a[1][0] - a[2][0] * a[1][2]);
    inv[1][1] =   a[2][2] * a[0][0] - a[2][0] * a[0][2]; 
    inv[1][2] = -(a[1][2] * a[0][0] - a[1][0] * a[0][2]);

    inv[2][0] =   a[2][1] * a[1][0] - a[2][0] * a[1][1];
    inv[2][1] = -(a[2][1] * a[0][0] - a[2][0] * a[0][1]);
    inv[2][2] =   a[1][1] * a[0][0] - a[1][0] * a[0][1];

    inv[0][0] /= det;
    inv[0][1] /= det;
    inv[0][2] /= det;

    inv[1][0] /= det;
    inv[1][1] /= det;
    inv[1][2] /= det;

    inv[2][0] /= det;
    inv[2][1] /= det;
    inv[2][2] /= det;
  }

    /**
     * TODO: Documentation
     *
     */
    public void crossProduct(float[] a, float[] b, float[] result)
    {
	result[0] = a[1] * b[2] - a[2] * b[1];
	result[1] = -a[0] * b[2] + a[2] * b[0];
	result[2] = a[0] * b[1] - a[1] * b[0];
    }

    /**
     * TODO: Documentation
     *
     */
    public void normalise(float[] vector)
    {
	float length= (float) Math.sqrt(vector[0] * vector[0] +
                                    vector[1] * vector[1] +
					vector[2] * vector[2]);

	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
    }

    // Determine the start point for the final scene's camera
    private void multiply(float[][] matrix, float[] vector, float[] result)
    {
      result[0] = matrix[0][0] * vector[0] +
	          matrix[0][1] * vector[1] +
	          matrix[0][2] * vector[2];

      result[1] = matrix[1][0] * vector[0] +
	          matrix[1][1] * vector[1] +
	          matrix[1][2] * vector[2];

      result[2] = matrix[2][0] * vector[0] +
	          matrix[2][1] * vector[1] +
	          matrix[2][2] * vector[2];
    }

}

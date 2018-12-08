/**
* This library helps with validation of input forms.
*
*
* # Definition
*
* @docs field, validity, event, submissionStatus, optionalField, validator, errorMessage
*
*
* # Helpers
*
* @docs extractError, field, preValidatedField, validate, validity, rawValue, optional, invalidate
*
*
* # Higher-Order Helpers
*
* @docs applyValidity, composite
*/


/**
* This type defines three state of field:
*
*   - `NotValidated` values e.g. in input from, which have not validated yet.
*   - `Valid a` values that they are correct.
*   - `Invalid(string)` and state for incorrect input values.
*/
type validity('a) =
  | NotValidated
  | Valid('a)
  | Invalid(string);

/**
* Define data type.
* For example:
*
* ```re
*     let dist = Field(40.5, NotValidated)
* ```
*
* That means `dist` has value 40.5 which hasn't validated yet.
*/
type field('raw, 'a) =
  | Field('raw, validity('a));

/**
*  Event describe state of input form:
*
*  - `OnSubmit` validates model data before submitting to server,
*    see `validateModel` in `example`.
*  - `OnBlur` validates input form when user leaves an input field.
*  - `OnRelatedChange` validates input form which is tied with another form.
*    For example: password and confirm form.
*  - `OnChange(`raw)` validates input form when user changes value in input field,
*/
type event(`raw) =
    | OnSubmit
    | OnBlur
    | OnRelatedChange
    | OnChange(`raw);

/**
* Here `submissionStatus` define states for submit data to server:
*
*  - `NotSubmitted` means that data have not sent yet.
*  - `InProcess` for data being processed.
*  - `Succeeded` if data have been successfully received.
*  - `Failed` or vice versa, data have not been successfully received.
*    This also may be used to inform user on screen, see `renderStatus`in `example`.
*/
type submissionStatus =
    | NotSubmitted
    | InProcess
    | Succeeded
    | Failed;

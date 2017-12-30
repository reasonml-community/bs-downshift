/* Common types */
type any;

/* Helpers */
let optionBoolToOptionJsBoolean = opt =>
  switch opt {
  | Some(true) => Some(Js.true_)
  | Some(false) => Some(Js.false_)
  | None => None
  };

/* Types for Downshift API */
type item = any;

type itemToString = item => string;

type selectedItemChanged = (item, item) => bool;

type a11yStatusMessageOptions = {
  .
  "highlightedIndex": option(int),
  "highlightedValue": any,
  "inputValue": string,
  "isOpen": bool,
  "itemToString": itemToString,
  "previousResultCount": int,
  "resultCount": int,
  "selectedItem": item
};

type getA11yStatusMessage = a11yStatusMessageOptions => string;

type rootPropsOptions = {. "refKey": string};

type itemPropsOptions = {
  .
  "index": option(int),
  "item": any
};

type controllerStateAndHelpers = {
  .
  /* Getters */
  "getRootProps": [@bs.meth] (rootPropsOptions => any),
  "getButtonProps": [@bs.meth] (ReactDOMRe.reactDOMProps => any),
  "getLabelProps": [@bs.meth] (ReactDOMRe.reactDOMProps => any),
  "getInputProps": [@bs.meth] (ReactDOMRe.reactDOMProps => any),
  "getItemProps": [@bs.meth] (itemPropsOptions => any),
  /* Actions */
  "openMenu": [@bs.meth] (unit => unit),
  "closeMenu": [@bs.meth] (unit => unit),
  "toggleMenu": [@bs.meth] (unit => unit),
  "reset": [@bs.meth] (unit => unit),
  "selectItem": [@bs.meth] (item => unit),
  "selectItemAtIndex": [@bs.meth] (int => unit),
  "selectHighlightedItem": [@bs.meth] (unit => unit),
  "setHighlightedIndex": [@bs.meth] (int => unit),
  "clearSelection": [@bs.meth] (unit => unit),
  "clearItems": [@bs.meth] (unit => unit),
  "itemToString": [@bs.meth] (any => unit),
  /* State */
  "highlightedIndex": Js.nullable(int),
  "inputValue": Js.nullable(string),
  "isOpen": bool,
  "selectedItem": any
};

type stateChangeOptions = {
  .
  "highlightedIndex": int,
  "inputValue": string,
  "isOpen": bool,
  "selectedItem": item
};

type onChange =
  (~selectedItem: any, ~stateAndHelpers: controllerStateAndHelpers) => unit;

type onSelect =
  (~selectedItem: any, ~stateAndHelpers: controllerStateAndHelpers) => unit;

type onStateChange =
  (
    ~changes: stateChangeOptions,
    ~stateAndHelpers: controllerStateAndHelpers
  ) =>
  unit;

type onInputValueChange =
  (~inputValue: string, ~stateAndHelpers: controllerStateAndHelpers) => unit;

type renderFunc = controllerStateAndHelpers => ReasonReact.reactElement;

/* Expose the React component with the mapped props */
[@bs.module "downshift"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~defaultSelectedItem: option(any)=?,
      ~defaultHighlightedIndex: option(int)=?,
      ~defaultInputValue: option(string)=?,
      ~defaultIsOpen: option(bool)=?,
      ~itemToString: option(itemToString)=?,
      ~selectedItemChanged: option(selectedItemChanged)=?,
      ~getA11yStatusMessage: option(getA11yStatusMessage)=?,
      ~onChange: option(onChange)=?,
      ~onSelect: option(onSelect)=?,
      ~onStateChange: option(onStateChange)=?,
      ~onInputValueChange: option(onInputValueChange)=?,
      ~itemCount: option(int)=?,
      ~highlightedIndex: option(int)=?,
      ~inputValue: option(string)=?,
      ~isOpen: option(bool)=?,
      ~selectedItem: option(any)=?,
      ~render: renderFunc,
      ~id: option(string)=?,
      ~environment: option(Dom.window)=?,
      ~onOuterClick: option(unit => unit)=?,
      _children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      "defaultSelectedItem": Js.Null_undefined.from_opt(defaultSelectedItem),
      "defaultHighlightedIndex":
        Js.Null_undefined.from_opt(defaultHighlightedIndex),
      "defaultInputValue": Js.Null_undefined.from_opt(defaultInputValue),
      "defaultIsOpen":
        Js.Null_undefined.from_opt(optionBoolToOptionJsBoolean(defaultIsOpen)),
      "itemToString": Js.Null_undefined.from_opt(itemToString),
      "selectedItemChanged": Js.Null_undefined.from_opt(selectedItemChanged),
      "getA11yStatusMessage": Js.Null_undefined.from_opt(getA11yStatusMessage),
      "onChange": Js.Null_undefined.from_opt(onChange),
      "onSelect": Js.Null_undefined.from_opt(onSelect),
      "onStateChange": Js.Null_undefined.from_opt(onStateChange),
      "onInputValueChange": Js.Null_undefined.from_opt(onInputValueChange),
      "itemCount": Js.Null_undefined.from_opt(itemCount),
      "highlightedIndex": Js.Null_undefined.from_opt(highlightedIndex),
      "inputValue": Js.Null_undefined.from_opt(inputValue),
      "isOpen": Js.Null_undefined.from_opt(optionBoolToOptionJsBoolean(isOpen)),
      "selectedItem": Js.Null_undefined.from_opt(selectedItem),
      "render": render,
      "id": Js.Null_undefined.from_opt(id),
      "environment": Js.Null_undefined.from_opt(environment),
      "onOuterClick": Js.Null_undefined.from_opt(onOuterClick)
    },
    [||]
  );
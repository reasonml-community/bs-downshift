/* Common types */
type any;

/* Helpers */
let optionBoolToOptionJsBoolean = opt =>
  switch opt {
  | Some(true) => Some(Js.true_)
  | Some(false) => Some(Js.false_)
  | None => None
  };

/* external objToJsObj : obj => Js.t({..}) = "%identity"; */
/* Types for Downshift API */
type item = any;

type otherStateToSet = Js.Dict.t(string);

type cb = unit => unit;

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

module ControllerStateAndHelpers = {
  type t;
  /* Getters */
  [@bs.send]
  external getRootProps : (~options: rootPropsOptions) => any = "getRootProps";
  [@bs.send]
  external getButtonProps : (~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "getButtonProps";
  [@bs.send]
  external getLabelProps : (~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "getLabelProps";
  [@bs.send]
  external getInputProps : (~options: ReactDOMRe.reactDOMProps=?, unit) => any =
    "getInputProps";
  [@bs.send]
  external itemPropsOptions : (~options: itemPropsOptions) => any =
    "itemPropsOptions";
  /* Actions */
  [@bs.send]
  external openMenu : ((~cb: cb=?, unit) => unit) => unit = "openMenu";
  [@bs.send]
  external closeMenu : ((~cb: cb=?, unit) => unit) => unit = "closeMenu";
  [@bs.send]
  external toggleMenu :
    ((~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit) => unit =
    "toggleMenu";
  [@bs.send]
  external reset :
    ((~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit) => unit =
    "reset";
  [@bs.send]
  external selectItem :
    (
      (~item: item, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
      unit
    ) =>
    unit =
    "selectItem";
  [@bs.send]
  external selectItemAtIndex :
    (
      (~index: int, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
      unit
    ) =>
    unit =
    "selectItemAtIndex";
  [@bs.send]
  external selectHighlightedItem :
    ((~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) => unit) => unit =
    "selectHighlightedItem";
  [@bs.send]
  external setHighlightedIndex :
    (
      (~index: int, ~otherStateToSet: otherStateToSet=?, ~cb: cb=?, unit) =>
      unit
    ) =>
    unit =
    "setHighlightedIndex";
  [@bs.send]
  external clearSelection : ((~cb: cb=?, unit) => unit) => unit =
    "clearSelection";
  [@bs.send] external clearItems : unit => unit = "clearItems";
  [@bs.send] external itemToString : item => unit = "itemToString";
  /* State */
  [@bs.val]
  external highlightedIndex : Js.Nullable.t(int) = "highlightedIndex";
  [@bs.val] external inputValue : Js.Nullable.t(string) = "inputValue";
  [@bs.val] external isOpen : bool = "isOpen";
  [@bs.val] external selectedItem : item = "selectedItem";
};

type stateChangeOptions = {
  .
  "highlightedIndex": int,
  "inputValue": string,
  "isOpen": bool,
  "selectedItem": item
};

type onChange =
  (~selectedItem: any, ~stateAndHelpers: ControllerStateAndHelpers.t) => unit;

type onSelect =
  (~selectedItem: any, ~stateAndHelpers: ControllerStateAndHelpers.t) => unit;

type onStateChange =
  (
    ~changes: stateChangeOptions,
    ~stateAndHelpers: ControllerStateAndHelpers.t
  ) =>
  unit;

type onInputValueChange =
  (~inputValue: string, ~stateAndHelpers: ControllerStateAndHelpers.t) => unit;

type renderFunc = ControllerStateAndHelpers.t => ReasonReact.reactElement;

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
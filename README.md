# `bs-downshift`

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Downshift](https://github.com/paypal/downshift) - **WIP**

## Demo

_Coming soon_

## Install and setup

#### yarn

```bash
$ yarn add bs-downshift
```

#### bsconfig

Add `bs-downshift` to your `bs-dependencies`: **bsconfig.json**

```json
"bs-dependencies": [
  "bs-downshift",
  "reason-react"
]
```

## Usage

See [examples](#examples) folder.

### Usage of `render` function

The `render` prop is a function that passes an object which contains _methods_ and _values_.

In ReasonML, this object is represented as a module called `ControllerStateAndHelpers`.

To make use of the _methods_ and _values_ within that module, you need to call it by passing the argument type (which is of type `ControllerStateAndHelpers.t` and does effectively the binding to the JS object method) like:

```js
render=(
  t => {
    ControllerStateAndHelpers.toggleMenu(t, ());
    /* ... */
  }
)
```

You can see that in the [examples](#examples) folder.
